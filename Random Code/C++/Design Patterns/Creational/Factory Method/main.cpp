#include <iostream>

class IParser {
public:
    virtual void parse() = 0;
    ~IParser() {}
};

class XMLParser : public IParser {
public:
    void parse() override {
        std::cout << "Parsing XML file" << std::endl;
    }
};

class JSONParser : public IParser {
public:
    void parse() override {
        std::cout << "Parsing JSON file" << std::endl;
    }
};

/// Parser Factory Class
enum class ParserType {
    XML,
    JSON
};

class ParserFactory {
public:
    static IParser* createParser(ParserType type) {
        switch (type) {
            case ParserType::XML:
                return new XMLParser();
            case ParserType::JSON:
                return new JSONParser();
            default:
                return nullptr;
        }
    }
};

/// Parser Factory Classes
class IParserFactory {
public:
    virtual IParser* create() = 0;
    virtual ~IParserFactory() {}

    void parse() {
        IParser* parser = this->create();
        parser->parse();
        delete parser;
    }
};

class XMLParserFactory : public IParserFactory {
public:
    IParser* create() override {
        return new XMLParser();
    }
};

class JSONParserFactory : public IParserFactory {
public:
    IParser* create() override {
        return new JSONParser();
    }
};

int main() {
    IParserFactory* factory = new XMLParserFactory();
    factory->parse();
    delete factory;
    factory = new JSONParserFactory();
    factory->parse();
    delete factory;
}