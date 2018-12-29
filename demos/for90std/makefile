CXX=g++

CFLAGS_NO = -fno-rtti -fno-exceptions

NO_WARN = -Wno-unused-label -Wno-unused-variable -Wno-char-subscripts -Wno-unused-but-set-variable -Wno-unused-value
NO_WARN_DEBUGING = -Wno-format-security -Wno-sign-compare -Wno-format-zero-length
CFLAGS = -Wall -DPOSIX -g -fpermissive -fPIC -std=c++17 $(NO_WARN) $(NO_WARN_DEBUGING) -ldl
OBJ_EXT = o
FOR90STD = ../../for90std/forlang.cpp

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

all: io filesys farray

io:
	$(CXX) $(CFLAGS) $(CFLAGS_COV_LNK) -o io io.cpp -L/usr/lib -I../../ /usr/local/lib/libgtest.a /usr/local/lib/for90std.a -lpthread 
filesys:
	$(CXX) $(CFLAGS) $(CFLAGS_COV_LNK) -o filesys filesys.cpp -L/usr/lib -I../../ /usr/local/lib/libgtest.a /usr/local/lib/for90std.a -lpthread 
farray:
	$(CXX) $(CFLAGS) $(CFLAGS_COV_LNK) -o farray farray.cpp -L/usr/lib -I../../ /usr/local/lib/libgtest.a /usr/local/lib/for90std.a -lpthread 

.PHONY: clean
clean:
	rm -rf io
	rm -rf filesys
	rm -rf farray
