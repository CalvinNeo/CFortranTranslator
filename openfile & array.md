## openfile 
7.14
```shell
program main
    open(unit=10,file='hello.txt')
    write(10,*)"xx"	
end program
```
1.Remove the first redundant `','`
`gen_callable.cpp`
line 158		`//string tail = ", ";`
line 196-198    
```shell
//		string tailed = taile + s;
//		tail = "";
//		return tailed;
```
2.change unkonwn to unknown
`gen_config`	line96
```shell
{ "foropenfile",{ { "unit", "int", "" }, { "iostat", "int", "" }, { "err", "forlabel", "" }, { "file", "string", "" }, { "status", "string", _WS("unknown") }
```
output
```shell
#include "../for90std/for90std.h"
#define USE_FORARRAY
int main()
{

        foropenfile(10, None, None, SS("hello.txt"), SS("unknown"), SS("sequential"), None, None, None, SS("rewind"), SS("readwrite"), None, None);
        return 0;
}

```
`forfilesys.cpp`
line 115 
line 131
`doreplace = true;`
Successfully create the file`"hello.txt"` and write `xx`.

## real,dimension a=1.0 
7.19
```shell
program main
real,dimension(3:5)::a=1.0
!real,dimension(3)::a=1.0
write(*,*) a
end program

```
### step1:
the number of array
change`gen_vardef.cpp`
in function `SliceBoundInfo get_lbound_size_from_slice(FunctionInfo * finfo, ParseNode & dimen_slice) `
`else if (dimen_slice.token_equals(TokenMeta::NT_DIMENSLICE)) `
the second     `, [](const ParseNode * x) {`
line 81

```shell
return to_string(u);
```
### step2	
change`farray.h`
`struct farray`

1. in function: `T & get(const size_type (& index)[X]) {`
```shell
for (size_type i = 0; i < X; i++)
{
	static int j=0;
	size_type off=0;
	if(index[i]<lb[i]){
		off = index[i]-1;
		j=index[i];
	}
	else if(j!=0) off = index[i]-lb[i]+j;
	else off = index[i]-lb[i];
	//size_type off = index[i] - ((index[i]<lb[i])?1:lb[i]);
    assert(off >= 0);
	it += (off) * delta[i];
}
```
2. add operator= overloading after `T & operator()(Args&&... args) {size_type index[sizeof...(args)] = { args... };
		return get(index);}`
```shell
	T & operator=(const T b){
		int x=*(this->sz);
		int y=*(this->lb);
		for(int j=1;j<y;j++){
			size_type index[1]={j};
			get(index)=0.0;
		}
        for(int i=y;i<=x;i++){
			
		   size_type index[1]={i};
			get(index)=b;
		}
		return *this->parr;
	}
```
Test
```shell
program main
real,dimension(3:5)::a=1.0
write(*,*) a
end program


#include "../for90std/for90std.h"
#define USE_FORARRAY
int main()
{
        farray<double> a {{3}, {5}};
        a = 1.0;
        forwritefree(stdout, a);
        return 0;
}



0.000000        0.000000        1.000000        1.000000        1.000000
```