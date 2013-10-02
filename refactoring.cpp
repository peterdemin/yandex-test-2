/////////////////   original-start   ///////////////////////

#include <string>
#include <iostream>
#include <stdexcept>

class CodeGenerator
{
public:
    enum Lang {JAVA, C_PLUS_PLUS, PHP};
    CodeGenerator(Lang language) { _language=language; }
    std::string generateCode()
    {
        switch(_language) {
            case JAVA: return std::string("java code") + someCodeRelatedThing();
            case C_PLUS_PLUS: return std::string("C++ code") + someCodeRelatedThing();
            case PHP: return std::string("PHP code") + someCodeRelatedThing();
        }
        throw new std::logic_error("Bad language");
    }

    std::string someCodeRelatedThing() // used in generateCode()
    {
        switch(_language) {
            case JAVA: return std::string("java-related stuff");
            case C_PLUS_PLUS: return std::string("C++-related stuff");
            case PHP: return std::string("PHP-related stuff");
        }
        throw new std::logic_error("Bad language");
    }

private:
    Lang _language;
};


int main() {
    CodeGenerator cg(CodeGenerator::C_PLUS_PLUS);
    std::cout << cg.generateCode() << std::endl;
    std::cout << cg.someCodeRelatedThing() << std::endl;
    return 0;
}

/////////////////   original-end   ///////////////////////
