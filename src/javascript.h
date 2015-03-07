#include "javascript/jsast.h"

class JavascriptParser{
public:
    JavascriptParser();
    ast::Program * parse(std::string name);
private:
};

