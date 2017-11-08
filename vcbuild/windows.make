EXE=../bin/CFortranTranslator.exe
CC=cl
LL=Link

LINK_LIB = /LIBPATH:"%boost_dir%\stage\lib" /LIBPATH:"%boost_dir%\libs"
LINK_DYNAMIC = /DYNAMICBASE "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib"
LINK_FLAG = /nologo /NXCOMPAT /subsystem:console /MACHINE:X64 /OPT:REF $(LINK_LIB) $(LINK_DYNAMIC)

MSVC_DONT_LINK=/c

MSVC_MACROS_R = /D "NDEBUG" /D "_CONSOLE" /D "_CRT_SECURE_NO_WARNINGS" /D "_SCL_SECURE_NO_WARNINGS" /D "_UNICODE" /D "UNICODE" 
MSVC_ERROR_R = /errorReport:prompt /EHsc /W3 /Gm-
MSVC_PERFORMANCE_R = /O2 /Oi /fp:precise /GS /GL /Gy
MSVC_DEBUGINGINFO_R = /Zi 
MSVC_ETC_R = /nologo /Zc:inline /Gd /MT 

CFLAGS_RELEASE = $(MSVC_MACROS_R) $(MSVC_ERROR_R) $(MSVC_PERFORMANCE_R) $(MSVC_ETC_R)
CFLAGS = $(CFLAGS_RELEASE)
OBJ_EXT = obj

SRC_ROOT=../
OBJ_ROOT=../bin/obj/release

OBJS=$(OBJ_ROOT)\farray.$(OBJ_EXT)  $(OBJ_ROOT)\for90std.$(OBJ_EXT)  $(OBJ_ROOT)\forfilesys.$(OBJ_EXT)  $(OBJ_ROOT)\forlang.$(OBJ_EXT)  $(OBJ_ROOT)\forstdio.$(OBJ_EXT)  $(OBJ_ROOT)\develop.$(OBJ_EXT)  $(OBJ_ROOT)\getopt2.$(OBJ_EXT)  $(OBJ_ROOT)\for90.flex.$(OBJ_EXT)  $(OBJ_ROOT)\for90.tab.$(OBJ_EXT)  $(OBJ_ROOT)\simple_lexer.$(OBJ_EXT)  $(OBJ_ROOT)\main.$(OBJ_EXT)  $(OBJ_ROOT)\attribute.$(OBJ_EXT)  $(OBJ_ROOT)\Function.$(OBJ_EXT)  $(OBJ_ROOT)\Intent.$(OBJ_EXT)  $(OBJ_ROOT)\parser.$(OBJ_EXT)  $(OBJ_ROOT)\scanner.$(OBJ_EXT)  $(OBJ_ROOT)\tokenizer.$(OBJ_EXT)  $(OBJ_ROOT)\Variable.$(OBJ_EXT)  $(OBJ_ROOT)\codegen.$(OBJ_EXT)  $(OBJ_ROOT)\gen_arraybuilder.$(OBJ_EXT)  $(OBJ_ROOT)\gen_attr_describer.$(OBJ_EXT)  $(OBJ_ROOT)\gen_callable.$(OBJ_EXT)  $(OBJ_ROOT)\gen_config.$(OBJ_EXT)  $(OBJ_ROOT)\gen_dimenslice.$(OBJ_EXT)  $(OBJ_ROOT)\gen_do.$(OBJ_EXT)  $(OBJ_ROOT)\gen_doc.$(OBJ_EXT)  $(OBJ_ROOT)\gen_exp.$(OBJ_EXT)  $(OBJ_ROOT)\gen_feature.$(OBJ_EXT)  $(OBJ_ROOT)\gen_function.$(OBJ_EXT)  $(OBJ_ROOT)\gen_if.$(OBJ_EXT)  $(OBJ_ROOT)\gen_io.$(OBJ_EXT)  $(OBJ_ROOT)\gen_label.$(OBJ_EXT)  $(OBJ_ROOT)\gen_paramtable.$(OBJ_EXT)  $(OBJ_ROOT)\gen_program.$(OBJ_EXT)  $(OBJ_ROOT)\gen_select.$(OBJ_EXT)  $(OBJ_ROOT)\gen_stmt.$(OBJ_EXT)  $(OBJ_ROOT)\gen_suite.$(OBJ_EXT)  $(OBJ_ROOT)\gen_type.$(OBJ_EXT)  $(OBJ_ROOT)\gen_vardef.$(OBJ_EXT)  $(OBJ_ROOT)\gen_variable.$(OBJ_EXT)  $(OBJ_ROOT)\lazygen.$(OBJ_EXT)  

CPPS=$(SRC_ROOT)\src\main.cpp  $(SRC_ROOT)\for90std\farray.cpp  $(SRC_ROOT)\for90std\for90std.cpp  $(SRC_ROOT)\for90std\forfilesys.cpp  $(SRC_ROOT)\for90std\forlang.cpp  $(SRC_ROOT)\for90std\forstdio.cpp  $(SRC_ROOT)\src\develop.cpp  $(SRC_ROOT)\src\getopt2.cpp  $(SRC_ROOT)\src\grammar\for90.flex.cpp  $(SRC_ROOT)\src\grammar\simple_lexer.cpp  $(SRC_ROOT)\src\parser\attribute.cpp  $(SRC_ROOT)\src\parser\Function.cpp  $(SRC_ROOT)\src\parser\Intent.cpp  $(SRC_ROOT)\src\parser\parser.cpp  $(SRC_ROOT)\src\parser\scanner.cpp  $(SRC_ROOT)\src\parser\tokenizer.cpp  $(SRC_ROOT)\src\parser\Variable.cpp  $(SRC_ROOT)\src\target\codegen.cpp  $(SRC_ROOT)\src\target\gen_arraybuilder.cpp  $(SRC_ROOT)\src\target\gen_attr_describer.cpp  $(SRC_ROOT)\src\target\gen_callable.cpp  $(SRC_ROOT)\src\target\gen_config.cpp  $(SRC_ROOT)\src\target\gen_dimenslice.cpp  $(SRC_ROOT)\src\target\gen_do.cpp  $(SRC_ROOT)\src\target\gen_doc.cpp  $(SRC_ROOT)\src\target\gen_exp.cpp  $(SRC_ROOT)\src\target\gen_feature.cpp  $(SRC_ROOT)\src\target\gen_function.cpp  $(SRC_ROOT)\src\target\gen_if.cpp  $(SRC_ROOT)\src\target\gen_io.cpp  $(SRC_ROOT)\src\target\gen_label.cpp  $(SRC_ROOT)\src\target\gen_paramtable.cpp  $(SRC_ROOT)\src\target\gen_program.cpp  $(SRC_ROOT)\src\target\gen_select.cpp  $(SRC_ROOT)\src\target\gen_stmt.cpp  $(SRC_ROOT)\src\target\gen_suite.cpp  $(SRC_ROOT)\src\target\gen_type.cpp  $(SRC_ROOT)\src\target\gen_vardef.cpp  $(SRC_ROOT)\src\target\gen_variable.cpp  $(SRC_ROOT)\src\target\lazygen.cpp  $(SRC_ROOT)\src\grammar\for90.tab.cpp

$(EXE): $(OBJS) 
  $(LL) $(LINK_FLAG) /out:$(EXE) $(OBJS)
  
$(OBJS): $(CPPS)
  md "$(OBJ_ROOT)"
  @echo generating .y
  start /B /WAIT /D "$(SRC_ROOT)/src/grammar/" win_bison.exe --output="for90.tab.cpp" --defines="for90.tab.h"  "for90.y"
  exit /b 0
  @echo compiling
  $(CC) $(MSVC_DONT_LINK) $(CFLAGS) /Fo"$(OBJ_ROOT)/" /I"%boost_dir%" $(CPPS) 

.PHONY : clean
clean:
  @rm -rf $(OBJ_ROOT)
