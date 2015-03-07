#include <stdio.h>
#include <iostream>
#include "javascript.h"
#include "javascript/jsast.h"

using namespace ast;

extern FILE *yyin;
extern int yyparse();
extern ast::Program* root;

JavascriptParser::JavascriptParser() {

}

Program * JavascriptParser::parse(std::string name) {
    // open a file handle to a particular file:
    FILE *myfile = fopen(name.c_str(), "r");
    // make sure it is valid:
    if (!myfile) {
        std::cout << "Can't open " << name << std::endl;
    }
    // set flex to read from it instead of defaulting to STDIN:
    yyin = myfile;
    // parse through the input until there is no more:
    do {
        yyparse();
    } while (!feof(yyin));

    return root;
}
