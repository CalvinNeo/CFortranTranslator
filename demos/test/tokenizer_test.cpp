#include <gtest/gtest.h>
#include "common.h"

void Check(int expect, std::string expect_s){
	int token = yylex();
	TokenizerState state = get_tokenizer_state();
	// printf("Check expect_s %s actual_s %s; expect %d actual %d\n", expect_s.c_str(), state.CurrentTerm.what.c_str(), expect, token);
	ASSERT_EQ(state.CurrentTerm.what, expect_s);
	ASSERT_EQ(token, expect);
	return;
}

void TestOnce(int expect, std::string expect_s, std::string code){
	printf("TEST '%s':\n");
	ResetToken(code);
	Check(expect, expect_s);
}

TEST(Comment, Basic){
	ResetToken("      1");
	Check(YY_INTEGER, "1");
	ResetToken("!     1\n2");
	Check(YY_CRLF, "\n");
	Check(YY_INTEGER, "2");
	ResetToken("c     1\n3");
	Check(YY_CRLF, "\n");
	Check(YY_INTEGER, "3");
	ResetToken("C     1\n4");
	Check(YY_CRLF, "\n");
	Check(YY_INTEGER, "4");
	ResetToken("common /go/ c");
	Check(0, "");
	ResetToken("if .true. then ! endif\n endif");
	Check(YY_IF, "if");
	Check(YY_TRUE, ".true.");
	Check(YY_THEN, "then");
	Check(YY_CRLF, "\n");
	Check(YY_ENDIF, "endif");
}


TEST(Continuation, Basic){
	ResetToken("1\n     *2");
	Check(YY_INTEGER, "12");
	ResetToken("1+\n     *3");
	Check(YY_INTEGER, "1");
	Check('+', "+");
	Check(YY_INTEGER, "3");
	ResetToken("1\nc2\n     *3");
}

TEST(Label, Basic){
	ResetToken("12345 6");
	Check(YY_LABEL, "12345");
	Check(YY_INTEGER, "6");

	ResetToken("do 123 i=1,3");
	Check(YY_DO, "do");
	Check(YY_WORD, "i");
	Check('=', "=");
	Check(YY_INTEGER, "1");
	Check(',', ",");
	Check(YY_INTEGER, "3");
	ASSERT_EQ(get_context().end_labels.size(), 1);
	ASSERT_EQ(get_context().end_labels["123"].size(), 1);
}

TEST(Literals, Numeral){
	ResetToken("1");
	Check(YY_INTEGER, "1");
	ResetToken("1.0");
	Check(YY_FLOAT, "1.0");
	ResetToken("1.0e2.0");
	Check(YY_FLOAT, "1.0e2.0");
	ResetToken("1.0e-2.0");
	Check(YY_FLOAT, "1.0e-2.0");
	ResetToken("1.0e-2");
	Check(YY_FLOAT, "1.0e-2");
	ResetToken("1e-2");
	Check(YY_FLOAT, "1e-2");
	ResetToken("1e-.2");
	Check(YY_FLOAT, "1e-0.2");
	ResetToken("1e.2");
	Check(YY_FLOAT, "1e0.2");
	ResetToken("3.");
	Check(YY_FLOAT, "3.0");
	ResetToken(".4");
	Check(YY_FLOAT, "0.4");
	ResetToken(".5e.6");
	Check(YY_FLOAT, "0.5e0.6");
}


TEST(Operators, Basic){
	ResetToken("1..gt.2.");
	Check(YY_FLOAT, "1.0");
	Check(YY_GT, ".gt.");
	Check(YY_FLOAT, "2.0");

	ResetToken("1..le..2");
	Check(YY_FLOAT, "1.0");
	Check(YY_LE, ".le.");
	Check(YY_FLOAT, "0.2");

	ResetToken("1e2..eq..3");
	Check(YY_FLOAT, "1e2.0");
	Check(YY_EQ, ".eq.");
	Check(YY_FLOAT, "0.3");


	ResetToken("1.e2..eq..3");
	Check(YY_FLOAT, "1.0e2.0");
	Check(YY_EQ, ".eq.");
	Check(YY_FLOAT, "0.3");

	ResetToken(".1e2..eq..3");
	Check(YY_FLOAT, "0.1e2.0");
	Check(YY_EQ, ".eq.");
	Check(YY_FLOAT, "0.3");


	ResetToken(".1e.2.eq..3");
	Check(YY_FLOAT, "0.1e0.2");
	Check(YY_EQ, ".eq.");
	Check(YY_FLOAT, "0.3");


	ResetToken("1.eq.2");
	Check(YY_INTEGER, "1");
	Check(YY_EQ, ".eq.");
	Check(YY_INTEGER, "2");

	ResetToken("KKK.EQ.1.OR.KKK.EQ.2");
	Check(YY_WORD, "kkk");
	Check(YY_EQ, ".eq.");
	Check(YY_INTEGER, "1");
	Check(YY_OROR, ".or.");
	Check(YY_WORD, "kkk");
	Check(YY_EQ, ".eq.");
	Check(YY_INTEGER, "2");


	ResetToken("KKK.GT.1..OR.KKK.EQ.2.");
	Check(YY_WORD, "kkk");
	Check(YY_GT, ".gt.");
	Check(YY_FLOAT, "1.0");
	Check(YY_OROR, ".or.");
	Check(YY_WORD, "kkk");
	Check(YY_EQ, ".eq.");
	Check(YY_FLOAT, "2.0");


}

TEST(Format, Basic){
	ResetToken("FORMAT(1X)");
	Check(YY_FORMAT_STMT, "(1X)");
	ResetToken("FORMAT('H')");
	Check(YY_FORMAT_STMT, "('H')");
	ResetToken("200     FORMAT(1X,\n     4 2X)");
	Check(YY_LABEL, "200");
	Check(YY_FORMAT_STMT, "(1X, 2X)");
	// `!` in format-stmt shouldn't be translated into comment start
	ResetToken("FORMAT(1X, I5), ! Y");
	Check(YY_FORMAT_STMT, "(1X, I5)");
	ResetToken("FORMAT(\"A\")");
	Check(YY_FORMAT_STMT, "(\"A\")");
	ResetToken("FORMAT(A,1H))");
	Check(YY_FORMAT_STMT, "(A,1H))");
	ResetToken("FORMAT('1X\"(',I4,2H)\")");
	Check(YY_FORMAT_STMT, "('1X\"(',I4,2H)\")");
}

TEST(LL2, Basic){
	ResetToken("else if");
	Check(YY_ELSEIF, "elseif");

	// Must Distinguish this go with those in goto-stmt
	// NOTICE If c is the first char in a new line, then it is a comment.
	ResetToken("      common /go/ c");
	Check(YY_COMMON, "common");
	Check('/', "/");
	Check(YY_WORD, "go");
	Check('/', "/");

}

int main(int argc, char ** argv){
    testing::InitGoogleTest(&argc, argv);
    auto r = RUN_ALL_TESTS();
    return r;
}
