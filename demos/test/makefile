CXX=g++

CFLAGS_NO = -fno-rtti -fno-exceptions

NO_WARN = -Wno-unused-label -Wno-unused-variable -Wno-char-subscripts -Wno-unused-but-set-variable -Wno-unused-value
NO_WARN_DEBUGING = -Wno-format-security -Wno-sign-compare -Wno-format-zero-length
CFLAGS = -Wall -DPOSIX -g -fpermissive -fPIC -std=c++17 $(NO_WARN) $(NO_WARN_DEBUGING) -ldl
OBJ_EXT = o
SRC_ROOT = ../..

include ../../build/objs.mk

cov_comp = -fprofile-arcs -ftest-coverage -fno-inline
cov_lnk = -fprofile-arcs -ftest-coverage --coverage -fno-inline 


ifeq ($(MODE), COV)
	# "Coverage mode"
	CFLAGS_COV = $(cov_comp)
	CFLAGS_COV_LNK = $(cov_lnk)
else
	# "Normal mode"
	CFLAGS_COV = 
	CFLAGS_COV_LNK = 
endif

all: tokenizer_test parser_test

tokenizer_test: tokenizer_test.cpp
	$(CXX) $(CFLAGS) $(CFLAGS_COV_LNK) -o tokenizer_test $(OBJSTRANS) tokenizer_test.cpp -L/usr/lib -I$(SRC_ROOT)/src /usr/local/lib/libgtest.a -lpthread 

parser_test: parser_test.cpp
	$(CXX) $(CFLAGS) $(CFLAGS_COV_LNK) -o parser_test $(OBJSTRANS) parser_test.cpp -L/usr/lib -I$(SRC_ROOT)/src /usr/local/lib/libgtest.a -lpthread 


.PHONY: clean
clean:
	rm -rf tokenizer_test
