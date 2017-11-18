EXE=CFortranTranslator
CXX=g++

CFLAGS2=-fno-rtti -fno-exceptions 
NO_WARN=-Wno-unused-label -Wno-unused-variable -Wno-char-subscripts -Wno-unused-but-set-variable -Wno-unused-value
CFLAGS=-Wall -DPOSIX -g -O3 -fpermissive -fPIC -std=c++17 $(NO_WARN)
OBJ_EXT=o

SRC_ROOT=../
OBJ_ROOT=./objs
OBJ_FOR90_ROOT=$(OBJ_ROOT)/for90std
OBJ_MAIN_ROOT=$(OBJ_ROOT)/
OBJ_GRAMMAR_ROOT=$(OBJ_ROOT)/src/grammar
OBJ_PARSER_ROOT=$(OBJ_ROOT)/src/parser
OBJ_TARGET_ROOT=$(OBJ_ROOT)/src/target
EXE_ROOT=../bin

OBJ_FOR90 = $(OBJ_FOR90_ROOT)/farray.$(OBJ_EXT)    $(OBJ_FOR90_ROOT)/for90std.$(OBJ_EXT)    $(OBJ_FOR90_ROOT)/forfilesys.$(OBJ_EXT)    $(OBJ_FOR90_ROOT)/forlang.$(OBJ_EXT)    $(OBJ_FOR90_ROOT)/forstdio.$(OBJ_EXT)

OBJ_MAIN = $(OBJ_MAIN_ROOT)/develop.$(OBJ_EXT)    $(OBJ_MAIN_ROOT)/main.$(OBJ_EXT)     $(OBJ_MAIN_ROOT)/getopt2.$(OBJ_EXT)

OBJ_GRAMMAR = $(OBJ_GRAMMAR_ROOT)/simple_lexer.$(OBJ_EXT)    $(OBJ_GRAMMAR_ROOT)/for90.tab.$(OBJ_EXT)

OBJ_PARSER = $(OBJ_PARSER_ROOT)/attribute.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/Function.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/Intent.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/parser.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/scanner.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/tokenizer.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/Variable.$(OBJ_EXT)

OBJ_TARGET = $(OBJ_TARGET_ROOT)/gen_common.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_arraybuilder.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_attr_describer.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_callable.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_config.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_dimenslice.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_do.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_doc.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_exp.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_feature.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_function.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_if.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_io.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_label.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_paramtable.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_program.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_select.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_stmt.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_suite.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_type.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_vardef.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_variable.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/lazygen.$(OBJ_EXT) 

OBJS = $(OBJ_FOR90) $(OBJ_MAIN) $(OBJ_GRAMMAR) $(OBJ_PARSER) $(OBJ_TARGET) 

$(EXE): $(OBJS) 
	$(CXX) $(CFLAGS) -o $(EXE) $(OBJS) -L/usr/lib/ -lboost_system -lboost_exception

$(EXE_ROOT):
	mkdir -p $(EXE_ROOT)
$(OBJ_FOR90_ROOT):
	mkdir -p $(OBJ_FOR90_ROOT)
$(OBJ_MAIN_ROOT):
	mkdir -p $(OBJ_MAIN_ROOT)
$(OBJ_GRAMMAR_ROOT):
	mkdir -p $(OBJ_GRAMMAR_ROOT)
$(OBJ_PARSER_ROOT):
	mkdir -p $(OBJ_PARSER_ROOT)
$(OBJ_TARGET_ROOT):
	mkdir -p $(OBJ_TARGET_ROOT)

$(OBJ_FOR90_ROOT)/%.$(OBJ_EXT): $(SRC_ROOT)/for90std/%.cpp $(OBJ_FOR90_ROOT)
	$(CXX) -c $(CFLAGS) $< -o $@

$(OBJ_MAIN_ROOT)/%.$(OBJ_EXT): $(SRC_ROOT)/src/%.cpp $(OBJ_FOR90_ROOT)
	$(CXX) -c $(CFLAGS) $< -o $@

$(OBJ_GRAMMAR_ROOT)/%.$(OBJ_EXT): $(SRC_ROOT)/src/grammar/%.cpp $(OBJ_GRAMMAR_ROOT)
	$(CXX) -c $(CFLAGS) $< -o $@

$(OBJ_PARSER_ROOT)/%.$(OBJ_EXT): $(SRC_ROOT)/src/parser/%.cpp $(OBJ_PARSER_ROOT)
	$(CXX) -c $(CFLAGS) $< -o $@

$(OBJ_TARGET_ROOT)/%.$(OBJ_EXT): $(SRC_ROOT)/src/target/%.cpp $(OBJ_TARGET_ROOT)
	$(CXX) -c $(CFLAGS) $< -o $@

$(SRC_ROOT)/src/grammar/for90.tab.cpp : $(SRC_ROOT)/src/grammar/for90.y
	bison -d -v $(SRC_ROOT)/src/grammar/for90.y -o $(SRC_ROOT)/src/grammar/for90.tab.cpp

.PHONY : clean
clean:
	rm -rf $(OBJ_ROOT)