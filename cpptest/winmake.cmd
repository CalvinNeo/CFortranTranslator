@echo "vcvarsall"
@call vcvarsall x86_amd64
@echo "nmake"
@nmake /nologo -f ./CMakeList.txt %1
@echo "finish"