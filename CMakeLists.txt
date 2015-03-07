cmake_minimum_required(VERSION 2.8.4)
project(jsrtl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
set(BISON_EXECUTABLE "C:/GnuWin32/bin/bison.exe")
set(FLEX_EXECUTABLE "C:/GnuWin32/bin/flex.exe")

include_directories (../llvm-3.4.src/llvm-3.4/include)
include_directories (../boost_1_57_0/boost_1_57_0/)
link_directories(res)

# Create target for the parser
add_custom_target(JavascriptParser echo "Creating parser.cpp")
add_custom_target(Dlls echo "Copying dlls")

# Create custom command for flex/lex (note the outputs)
 ADD_CUSTOM_COMMAND(
   SOURCE ${CMAKE_SOURCE_DIR}/res/javascript/scanner.lexer
   COMMAND ${FLEX_EXECUTABLE}
   ARGS -o${CMAKE_SOURCE_DIR}/src/javascript/lexer.cpp
        ${CMAKE_SOURCE_DIR}/res/javascript/scanner.lexer
   TARGET JavascriptParser
   OUTPUTS ${CMAKE_SOURCE_DIR}/src/javascript/lexer.cpp)

# Create custom command for bison/yacc (note the DEPENDS)
 ADD_CUSTOM_COMMAND(
   SOURCE ${CMAKE_SOURCE_DIR}/res/javascript/parser.grammar
   COMMAND ${BISON_EXECUTABLE}
   ARGS -y ${CMAKE_SOURCE_DIR}/res/javascript/parser.grammar
        --defines=${CMAKE_SOURCE_DIR}/src/javascript/parser.h
        -o ${CMAKE_SOURCE_DIR}/src/javascript/parser.cpp
   TARGET JavascriptParser
   DEPENDS ${CMAKE_SOURCE_DIR}/src/javascript/lexer.cpp
   OUTPUTS ${CMAKE_SOURCE_DIR}/src/javascript/parser.cpp)

# Since parser.c does not exists yet when cmake is run, mark
# it as generated
SET_SOURCE_FILES_PROPERTIES(${CMAKE_SOURCE_DIR}/src/javascript/parser.cpp GENERATED)
SET_SOURCE_FILES_PROPERTIES(${CMAKE_SOURCE_DIR}/src/javascript/lexer.cpp GENERATED)

add_custom_command(
    TARGET Dlls
    POST_BUILD
    COMMAND ${CMAKE_COMMAND}
        -E copy_if_different
        ${CMAKE_SOURCE_DIR}/libs/LLVM-3.4.dll $<TARGET_FILE_DIR:jsrtl>
    COMMENT "Copying dlls"
)

set(SOURCE_FILES main.cpp src/javascript.cpp ${CMAKE_SOURCE_DIR}/src/javascript/parser.cpp ${CMAKE_SOURCE_DIR}/src/javascript/lexer.cpp)
add_executable(jsrtl ${SOURCE_FILES})

target_link_libraries(jsrtl LLVM-3.4)

