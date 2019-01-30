#include <gtest/gtest.h>
#include "common.h"

ParseNode * LocateNode(std::string path, ParseNode * nd){
	int i;
	int pos_delta = 0, pos = 0;
	while(sscanf(path.c_str() + pos, "%d%n", &i, &pos_delta) == 1){
		nd = &(nd->get(i));
		pos += pos_delta;
	}
	return nd;
}

ParseNode * LocateNode(std::string path){
	return LocateNode(path, &get_context().program_tree);
}

TEST(Do, All){
	// Non-block do
	ResetParser("do 1 i = 1, m\ndo 1 j = 1, m \n1     continue");
	// preorder(&get_context().program_tree);
	ASSERT_EQ(LocateNode("0 0")->get_token(), TokenMeta::NT_DORANGE);
	ASSERT_EQ(LocateNode("0 0 0")->get_what(), "i");
	ASSERT_EQ(LocateNode("0 0 1")->get_token(), TokenMeta::META_INTEGER);
	ASSERT_EQ(LocateNode("0 0 2")->get_what(), "m");
	ASSERT_EQ(LocateNode("0 0 3")->get_token(), TokenMeta::META_INTEGER);
	ASSERT_EQ(LocateNode("0 0 4 0")->get_token(), TokenMeta::NT_DORANGE);

	ResetParser("do\n continue\n enddo");
	ASSERT_EQ(LocateNode("0 0")->get_token(), TokenMeta::NT_DO);
}

TEST(Define, Common){
	ResetParser(" common /ca/ a, b, c(10)\n common // g");
	ASSERT_EQ(get_context().commonblocks.size(), 2);
	CommonBlockInfo * info = get_context().commonblocks["ca"];
	ASSERT_EQ(info->variables.size(), 3);
	info = get_context().commonblocks["G"];
	ASSERT_EQ(info->variables.size(), 1);

	ResetParser(" common /ca/ a, b, c\nsubroutine sub\ncommon /ca/ aa, bb, cc\nendsubroutine");
	// printf("%s\n", get_context().program_tree.get_what().c_str());
	ASSERT_EQ(get_context().commonblocks.size(), 1);
	info = get_context().commonblocks["ca"];
	ASSERT_EQ(info->variables.size(), 3);
	// a,b,c,aa,bb,cc
	ASSERT_EQ(get_context().variables.size(), 6);
}


TEST(Define, Implicit){
	ResetParser("implicit integer(a-c)\n a = 1\ni = 1\nd = 1\ninteger e\n");
	ASSERT_EQ(get_context().variables["::program::a"]->type.get_token(), TokenMeta::META_INTEGER);
	ASSERT_EQ(get_context().variables["::program::a"]->implicit_defined, true);
	ASSERT_EQ(get_context().variables["::program::i"]->type.get_token(), TokenMeta::META_INTEGER);
	ASSERT_EQ(get_context().variables["::program::d"]->type.get_token(), TokenMeta::META_REAL);
	ASSERT_EQ(get_context().variables["::program::e"]->type.get_token(), TokenMeta::META_INTEGER);
	ASSERT_EQ(get_context().variables["::program::e"]->implicit_defined, false);
	ResetParser("integer, intent(in)::a = c");
	ASSERT_EQ(get_context().variables.size(), 2);
	ASSERT_EQ(get_context().variables["::program::a"]->type.get_what(), "int");
	ASSERT_EQ(get_context().variables["::program::c"]->type.get_what(), "double");
	ResetParser("integer, intent(out)::a = c(3)");
	ASSERT_EQ(get_context().variables["::program::a"]->type.get_what(), "int");
	ASSERT_EQ(get_context().variables["::program::c"]->type.get_what(), "double");
	ResetParser("read *, a, b(1)");
	ASSERT_EQ(get_context().variables["::program::a"]->type.get_what(), "double");
	ASSERT_EQ(get_context().variables["::program::b"]->type.get_what(), "double");
	ResetParser("func(a + 3)");
	ASSERT_EQ(get_context().variables["::program::a"]->type.get_what(), "double");
	ResetParser("a(1) = b(1)");
	ASSERT_EQ(get_context().variables["::program::a"]->type.get_what(), "double");
	ASSERT_EQ(get_context().variables["::program::b"]->type.get_what(), "double");
	ResetParser("subroutine b(X)\nendsubroutine\n a(1) = b(1)");
	ASSERT_EQ(get_context().variables.size(), 2);
	ASSERT_EQ(get_context().functions.size(), 3); // ::, ::program, ::b
	ASSERT_EQ(get_context().variables["::program::a"]->type.get_what(), "double");
	ASSERT_EQ(get_context().variables["::b::x"]->type.get_what(), "double");
}

TEST(Define, Basic){
	ResetParser(" integer i = j + 1");
	ResetParser(" integer::i = j + 1");
	ResetParser(" character *3 s1\n character *3 s2\n character c");
	ASSERT_EQ(get_context().variables.size(), 3);
	ASSERT_EQ(get_context().variables["::program::s1"]->type.get_token(), TokenMeta::META_STRING);
	ASSERT_EQ(get_context().variables["::program::s1"]->is_array(), false);
	ASSERT_EQ(get_context().variables["::program::s2"]->type.get_token(), TokenMeta::META_STRING);
	ASSERT_EQ(get_context().variables["::program::s2"]->is_array(), false);
}

TEST(Define, Array){
	ResetParser("dimension arr(10), j");
}

TEST(Define, Kind){
	ResetParser("integer(kind=2)::i = int(j)");
	ASSERT_EQ(get_context().variables.size(), 2);
	ASSERT_EQ(get_context().variables["::program::i"]->type.get_what(), "int16_t");
	ASSERT_EQ(get_context().variables["::program::i"]->desc.kind, 2);
	ResetParser("implicit double precision(d)\nd = 1");
	ASSERT_EQ(get_context().variables["::program::d"]->type.get_what(), "double");
}

std::string get_typestr(std::string type_name, bool in_paramtable){
	return gen_qualified_typestr(get_context().variables[type_name]->type, get_context().variables[type_name]->desc, in_paramtable);
}

TEST(Define, Qualifier){
	ResetParser("integer, parameter, save::i = 10");
	ASSERT_EQ(get_context().variables["::program::i"]->desc.constant, true);
	ASSERT_EQ(get_context().variables["::program::i"]->desc.save, true);
	ResetParser("integer, intent(in)::i = 1");
	ASSERT_EQ(get_context().variables["::program::i"]->desc.reference, true);
	ASSERT_EQ(get_typestr("::program::i", false), "const int &");
	ResetParser("integer, intent(out)::i = arr(1)");
	ASSERT_EQ(get_context().variables["::program::i"]->desc.reference, true);
	ASSERT_EQ(get_typestr("::program::i", false), "int &");
	ResetParser("integer, intent(inout)::i = arr(1)");
	ASSERT_EQ(get_context().variables["::program::i"]->desc.inout_reference, true);
	// TODO Check if error here?
	ASSERT_EQ(get_typestr("::program::i", false), "int &&");
	ResetParser("integer, optional::i = arr(1)");
	ASSERT_EQ(get_context().variables["::program::i"]->desc.optional, true);
	ASSERT_EQ(get_typestr("::program::i", false), "foroptional<int>");


	ResetParser("subroutine f(i)\ninteger, parameter, save::i = 10\nendsubroutine");
	ASSERT_EQ(get_context().variables["::f::i"]->desc.constant, true);
	ASSERT_EQ(get_context().variables["::f::i"]->desc.save, true);
	ResetParser("subroutine f(i)\ninteger, intent(in)::i = 1\nendsubroutine");
	ASSERT_EQ(get_context().variables["::f::i"]->desc.reference, true);
	ASSERT_EQ(get_typestr("::f::i", true), "const int &");
	ResetParser("subroutine f(i)\ninteger, intent(out)::i = arr(1)\nendsubroutine");
	ASSERT_EQ(get_context().variables["::f::i"]->desc.reference, true);
	ASSERT_EQ(get_typestr("::f::i", true), "int &");
	ResetParser("subroutine f(i)\ninteger, intent(inout)::i = arr(1)\nendsubroutine");
	ASSERT_EQ(get_context().variables["::f::i"]->desc.inout_reference, true);
	ASSERT_EQ(get_typestr("::f::i", true), "int &&");
	ResetParser("subroutine f(i)\ninteger, optional::i = arr(1)\nendsubroutine");
	ASSERT_EQ(get_context().variables["::f::i"]->desc.optional, true);
	ASSERT_EQ(get_typestr("::f::i", true), "foroptional<int>");
	ResetParser("subroutine f(i)\ninteger::i = 10\nendsubroutine");
	ASSERT_EQ(get_typestr("::f::i", true), "int &&");
}

TEST(Fixed, Comment){
	ResetParser("character c");
	ResetParser("common /a/ a");
	ResetParser(" character c");
	ResetParser("!中文注释!comment");
	ResetParser("c中文注释!comment");
	ResetParser("12345 !comment");
	// In order to comply with gfortran
	ResetParser("c_also_comment = 1");
	ASSERT_EQ(get_context().variables.size(), 0);
	ResetParser("c-1");
	ASSERT_EQ(get_context().variables.size(), 0);
	ResetParser("subroutine s1\n  call s2(1)\nendsubroutine\n !comment\nsubroutine s2(x)\nendsubroutine\n ");
}

TEST(Fixed, Continuation){
	ResetParser("dimension arr1(10)\n     *, arr2(10)");
	ASSERT_EQ(get_context().variables.size(), 2);
	ResetParser("a .and !comment\n     .. b");
	// preorder(&get_context().program_tree);
	ASSERT_EQ(get_context().variables.size(), 2);
	ASSERT_EQ(LocateNode("0 0")->get_token(), TokenMeta::NT_STATEMENT);
	ASSERT_EQ(LocateNode("0 0 0")->get_token(), TokenMeta::NT_EXPRESSION);
	ASSERT_EQ(LocateNode("0 0 0 0")->get_what(), "a");
	ASSERT_EQ(LocateNode("0 0 0 1")->get_what(), "b");
	// In order to be compatible with some old fortran codes, `\t` is handled as 5 spaces here.
	ResetParser("a .and !comment\n\t.. b");
	ASSERT_EQ(get_context().variables.size(), 2);
	ASSERT_EQ(LocateNode("0 0")->get_token(), TokenMeta::NT_STATEMENT);
	ASSERT_EQ(LocateNode("0 0 0")->get_token(), TokenMeta::NT_EXPRESSION);
	ASSERT_EQ(LocateNode("0 0 0 0")->get_what(), "a");
	ASSERT_EQ(LocateNode("0 0 0 1")->get_what(), "b");
}


TEST(Statement, Basic){
	ResetParser("a = b; c = d");
	ASSERT_EQ(LocateNode("0 0")->get_token(), TokenMeta::NT_STATEMENT);
	ASSERT_EQ(LocateNode("0 0 0")->get_token(), TokenMeta::NT_EXPRESSION);
	ASSERT_EQ(LocateNode("1 0")->get_token(), TokenMeta::NT_STATEMENT);
	ASSERT_EQ(LocateNode("1 0 0")->get_token(), TokenMeta::NT_EXPRESSION);
	ResetParser("111   call f(1)\ngoto 111");
	ResetParser("pause\nstop\ncontinue");
}

TEST(IO, Format){
	// `write` can use format defined later at label `12`.
	ResetParser("11    write(*, 12) a, b, c, arr(1), a, b, c, arr(2)\n12    format(2(3I,F))");
	ResetParser("3     format(3I)\nread (3, 3) a, b, c");
	ResetParser("11    format(/50X,2(2I3))\nprint 11, 1, 2, 3, 4");
	ResetParser("12    format('A'/2(2I3))\n print 12, 1, 2, 3, 4");
	ResetParser("13    format(2F10.3,' ',2H(\",I4,2H)\")\nprint 13, 1.1, 2.2, 1, 2, 3, 4");
	ResetParser("14    format(5HCOLOR,' ',I1)\nprint 14, 1");
	ResetParser("15    format(F10.3,'( \n\"',I1,2H)\")\nprint 15, 1.1, 1");
	ResetParser("read (*,*) i");
	ResetParser("open(1, FILE=\"f\")");
	ResetParser("write(1,*) (a, b, i=1,2)");
	ResetParser("write(2,*) ((a(i,j), j=1,i), i=1,10)");
}


TEST(Paramtable, Basic){
	ResetParser("A(1, 2, 3)");
	ResetParser("B()");
	ResetParser("C(1, 2:2, 3)");
	ResetParser("D(1:2, 2, 3)");
	// ResetParser("subroutine e(a, c, d)\nendsubroutine\nE(1, c = 2, d = 3)");
}

TEST(Function, Define){
	ResetParser("function t(x, y) result(r)\nreal::r\nendfunction\nsubroutine s\nimplicit none\nt(1,2)\n;\ny\n\n100\nend subroutine");
	ASSERT_EQ(get_context().functions.size(), 4);
	ASSERT_EQ(get_context().functions["::s"]->local_name, "s");
	ASSERT_EQ(get_context().functions["::t"]->result_name, "r");
	ASSERT_EQ(get_context().functions["::t"]->funcdesc.declared_variables.size(), 3);
}

TEST(Function, Interface){
}

int main(int argc, char ** argv){
	testing::InitGoogleTest(&argc, argv);
	auto r = RUN_ALL_TESTS();
	return r;
}
