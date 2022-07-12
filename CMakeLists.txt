#
# CMake for CFortranTranslator
#
cmake_minimum_required (VERSION 3.10)
project (cppduals CXX)

#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_DISABLE_IN_SOURCE_BUILD ON)
if (NOT CMAKE_CONFIGURATION_TYPES AND 
    NOT CMAKE_NO_BUILD_TYPE AND
    NOT CMAKE_BUILD_TYPE AND
    CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  set (CMAKE_BUILD_TYPE RelWithDebInfo)
  set_property (CACHE CMAKE_BUILD_TYPE PROPERTY
    STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
  
include (ExternalProject)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

if (NOT WIN32)
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wno-enum-compare")
endif ()

find_package (BISON REQUIRED)
find_package (Boost REQUIRED)

bison_target (for90 src/grammar/for90.y ${CMAKE_CURRENT_BINARY_DIR}/for90.cpp)
include_directories (${CMAKE_SOURCE_DIR}/src/grammar/ /usr/local/include/)

set (CPPS
  src/main.cpp
  for90std/farray.cpp  
  for90std/for90std.cpp  
  for90std/forfilesys.cpp  
  for90std/forlang.cpp  
  for90std/forstdio.cpp  
  src/develop.cpp  
  src/getopt2.cpp  
  src/grammar/simple_lexer.cpp  
  src/parser/attribute.cpp  
  src/parser/Function.cpp  
  src/parser/Intent.cpp
  src/parser/IntentHelper.cpp
  src/parser/Type.cpp
  src/parser/parser.cpp
  src/parser/scanner.cpp
  src/parser/tokenizer.cpp  
  src/parser/Variable.cpp  
  src/target/gen_common.cpp  
  src/target/gen_arraybuilder.cpp  
  src/target/gen_attr_describer.cpp  
  src/target/gen_callable.cpp  
  src/target/gen_config.cpp  
  src/target/gen_dimenslice.cpp  
  src/target/gen_do.cpp  
  src/target/gen_doc.cpp  
  src/target/gen_exp.cpp  
  src/target/gen_feature.cpp  
  src/target/gen_function.cpp  
  src/target/gen_if.cpp  
  src/target/gen_io.cpp  
  src/target/gen_label.cpp  
  src/target/gen_paramtable.cpp  
  src/target/gen_program.cpp  
  src/target/gen_select.cpp  
  src/target/gen_stmt.cpp  
  src/target/gen_suite.cpp  
  src/target/gen_type.cpp  
  src/target/gen_vardef.cpp  
  src/target/gen_variable.cpp  
  src/target/lazygen.cpp  
  ${BISON_for90_OUTPUTS} #src/grammar/for90.tab.cpp
  )

add_executable (CFortranTranslator ${CPPS})
