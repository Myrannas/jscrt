#include <iostream>
#include "src/javascript.h"

using namespace std;

int main(int argc, char** argv) {
    JavascriptParser *parser = new JavascriptParser();
    ast::Program* program = parser->parse("res/test.js");
    program->execute();
    return 0;
}