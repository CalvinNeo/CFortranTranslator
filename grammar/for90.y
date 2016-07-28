# Grammar for Fortran90
%%
# lexer
int [-+]?[0-9_]+
float [-+]?[0-9\._]+([eE][0-9\._]+)?
name [a-zA-Z_][a-zA-Z0-9]*
str (".*"|'.*')
true .true.
false .false.
vartype (real|integer|complex|logical|character)
keyword #############
%%
# reserved | + [] \ ``
complex (float,float)
const int|float
left name
right int|float|name|str
index name|int
slice index:index[:index]
substr name(slice)
array name(int|name)
argtable name[=right]|argtable, name[=right]
vardef vartype::argtable
stmt simple_stmt | compound_stmt
simple_stmt: small_stmt (`;` small_stmt)* [`;`] NEWLINE
compound_stmt: if_stmt | while_stmt | for_stmt
do_stmt `do` left = right , right

