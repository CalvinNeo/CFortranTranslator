OBJ_ROOT = $(SRC_ROOT)/build/objs
OBJ_FOR90_ROOT = $(OBJ_ROOT)/for90std
OBJ_MAIN_ROOT = $(OBJ_ROOT)/src
OBJ_GRAMMAR_ROOT = $(OBJ_ROOT)/src/grammar
OBJ_PARSER_ROOT = $(OBJ_ROOT)/src/parser
OBJ_TARGET_ROOT = $(OBJ_ROOT)/src/target
EXE_ROOT = $(SRC_ROOT)/bin
GCOV_ROOT = $(OBJ_ROOT)

# Not all files in a folder is included
OBJ_FOR90 = $(OBJ_FOR90_ROOT)/farray.$(OBJ_EXT)    $(OBJ_FOR90_ROOT)/for90std.$(OBJ_EXT)    $(OBJ_FOR90_ROOT)/forfilesys.$(OBJ_EXT)    $(OBJ_FOR90_ROOT)/forlang.$(OBJ_EXT)    $(OBJ_FOR90_ROOT)/forstdio.$(OBJ_EXT)
OBJ_MAIN = $(OBJ_MAIN_ROOT)/develop.$(OBJ_EXT)    $(OBJ_MAIN_ROOT)/main.$(OBJ_EXT)     $(OBJ_MAIN_ROOT)/getopt2.$(OBJ_EXT)
OBJ_GRAMMAR = $(OBJ_GRAMMAR_ROOT)/simple_lexer.$(OBJ_EXT)    $(OBJ_GRAMMAR_ROOT)/for90.tab.$(OBJ_EXT)
OBJ_PARSER = $(OBJ_PARSER_ROOT)/attribute.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/Function.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/Intent.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/parser.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/tokenizer.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/Variable.$(OBJ_EXT) $(OBJ_PARSER_ROOT)/Type.$(OBJ_EXT)
OBJ_TARGET = $(patsubst $(SRC_ROOT)%, $(OBJ_ROOT)%, $(patsubst %cpp, %$(OBJ_EXT), $(wildcard $(SRC_ROOT)/src/target/*.cpp)))
OBJS = $(OBJ_FOR90) $(OBJ_MAIN) $(OBJ_GRAMMAR) $(OBJ_PARSER) $(OBJ_TARGET) 
OBJSTRANS = $(OBJ_GRAMMAR) $(OBJ_PARSER) $(OBJ_TARGET) 

GCOVS_T = $(patsubst %o,%gcov,$(OBJS))
GCOVS = $(patsubst $(OBJ_ROOT)%,$(GCOV_ROOT)%,$(GCOVS_T))

SRCS += $(wildcard $(SRC_ROOT)/for90std/*.cpp)
SRCS += $(wildcard $(SRC_ROOT)/src/*.cpp)
SRCS += $(wildcard $(SRC_ROOT)/src/grammar/*.cpp)
SRCS += $(wildcard $(SRC_ROOT)/src/parser/*.cpp)
SRCS += $(wildcard $(SRC_ROOT)/src/target/*.cpp)
SRCS += $(wildcard $(SRC_ROOT)/for90std/*.h)
SRCS += $(wildcard $(SRC_ROOT)/src/*.h)
SRCS += $(wildcard $(SRC_ROOT)/src/grammar/*.h)
SRCS += $(wildcard $(SRC_ROOT)/src/parser/*.h)
SRCS += $(wildcard $(SRC_ROOT)/src/target/*.h)
SRCS += $(wildcard $(SRC_ROOT)/src/grammar/*.y)
