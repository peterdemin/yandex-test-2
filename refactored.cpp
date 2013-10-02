/////////////////   refactored-start   ///////////////////////

#include <string>
#include <stdexcept>
#include <iostream>

class AbstractGenerator {
public:
    virtual std::string generateCode() = 0;
    virtual std::string someCodeRelatedThing() = 0;
};

class JavaGenerator : public AbstractGenerator {
public:
    std::string generateCode() {
        return std::string("java code") + someCodeRelatedThing();
    }

    std::string someCodeRelatedThing() {
        return std::string("java-related stuff");
    }
};

class CppGenerator : public AbstractGenerator {
public:
    std::string generateCode() {
        return std::string("C++ code") + someCodeRelatedThing();
    }

    std::string someCodeRelatedThing() {
        return std::string("C++-related stuff");
    }
};

class PhpGenerator : public AbstractGenerator {
public:
    std::string generateCode() {
        return std::string("PHP code") + someCodeRelatedThing();
    }

    std::string someCodeRelatedThing() {
        return std::string("PHP-related stuff");
    }
};


class CodeGenerator : public AbstractGenerator {
public:
    enum Lang {JAVA, C_PLUS_PLUS, PHP};
    CodeGenerator(Lang language) {
        switch(language) {
            case JAVA:
                specific = new JavaGenerator();
                break;
            case C_PLUS_PLUS:
                specific = new CppGenerator();
                break;
            case PHP:
                specific = new PhpGenerator();
                break;
            default:
                specific = 0;
                throw new std::logic_error("Bad language");
                break;
        }
    }
    virtual std::string generateCode(){
        return specific->generateCode();
    }
    virtual std::string someCodeRelatedThing(){
        return specific->someCodeRelatedThing();
    }
    ~CodeGenerator() {
        delete specific;
    }

private:
    AbstractGenerator *specific;
};

int main() {
    CodeGenerator cg(CodeGenerator::C_PLUS_PLUS);
    std::cout << cg.generateCode() << std::endl;
    std::cout << cg.someCodeRelatedThing() << std::endl;
    return 0;
}

/////////////////   refactored-end   ///////////////////////
