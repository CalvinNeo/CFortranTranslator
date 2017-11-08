@echo vcvarsall
@call vcvarsall x86_amd64
@set PATH=%boost_dir%;%boost_dir%\stage\lib;%boost_dir%\libs;%PATH%
@set LIB=%boost_dir%;%boost_dir%\stage\lib;%boost_dir%\libs;%LIB%
@echo nmake
@nmake /nologo -f ./windows.make %1
@echo finish