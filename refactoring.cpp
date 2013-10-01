#include <string>
#include <stdexcept>

class CodeGenerator
{
public:
    enum Lang {JAVA, C_PLUS_PLUS, PHP};
    CodeGenerator(Lang language) { _language=language; }
    std::string generateCode()
    {
        switch(_language) {
            case JAVA: return std::string("java code");
            case C_PLUS_PLUS: return std::string("C++ code");
            case PHP: return std::string("PHP code");
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
    return 0;
}
