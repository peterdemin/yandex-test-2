#include <string>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <map>

class CodeGenerator {
public:
    enum Lang {JAVA, C_PLUS_PLUS, PHP};
    CodeGenerator(Lang language);
    virtual std::string generateCode();
    virtual std::string someCodeRelatedThing();
    virtual ~CodeGenerator();
protected:
    CodeGenerator() {}
private:
    CodeGenerator *specific;
};

class JavaGenerator : public CodeGenerator {
public:
    std::string generateCode() {
        return std::string("Java code") + someCodeRelatedThing();
    }

    std::string someCodeRelatedThing() {
        return std::string("java-related stuff");
    }
};

class CppGenerator : public CodeGenerator {
public:
    std::string generateCode() {
        return std::string("Cpp code") + someCodeRelatedThing();
    }

    std::string someCodeRelatedThing() {
        return std::string("C++-related stuff");
    }
};

class PhpGenerator : public CodeGenerator {
public:
    std::string generateCode() {
        return std::string("Php code") + someCodeRelatedThing();
    }

    std::string someCodeRelatedThing() {
        return std::string("PHP-related stuff");
    }
};

CodeGenerator::CodeGenerator(Lang language) {
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

std::string CodeGenerator::generateCode() {
    return specific->generateCode();
}

std::string CodeGenerator::someCodeRelatedThing() {
    return specific->someCodeRelatedThing();
}

CodeGenerator::~CodeGenerator() {
    delete specific;
}


int main() {
    CodeGenerator cg(CodeGenerator::C_PLUS_PLUS);
    std::cout << cg.generateCode() << std::endl;
    std::cout << cg.someCodeRelatedThing() << std::endl;
    return 0;
}
