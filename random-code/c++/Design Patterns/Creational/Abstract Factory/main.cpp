#include <iostream>
#include <string>

class Mouse {
public:
    virtual ~Mouse() {}
    virtual void click() = 0;
    virtual void scroll() = 0;
};

class LogitechMouse : public Mouse {
public:
    void click() override {
        std::cout << "Logitech mouse click" << std::endl;
    }

    void scroll() override {
        std::cout << "Logitech mouse scroll" << std::endl;
    }
};

class RazerMouse : public Mouse {
public:
    void click() override {
        std::cout << "Razer mouse click" << std::endl;
    }

    void scroll() override {
        std::cout << "Razer mouse scroll" << std::endl;
    }
};

class Keyboard {
public:
    virtual ~Keyboard() = default;
    virtual void type() = 0;
};

class LogitechKeyboard : public Keyboard {
public:
    void type() override {
        std::cout << "Logitech keyboard type" << std::endl;
    }
};

class RazerKeyboard : public Keyboard {
public:
    void type() override {
        std::cout << "Razer keyboard type" << std::endl;
    }
};

class Factory {
public:
    virtual ~Factory() = default;
    virtual Mouse* createMouse() = 0;
    virtual Keyboard* createKeyboard() = 0;
};

class LogitechFactory : public Factory {
public:
    Mouse* createMouse() override {
        return new LogitechMouse();
    }

    Keyboard* createKeyboard() override {
        return new LogitechKeyboard();
    }
};

class RazerFactory : public Factory {
public:
    Mouse* createMouse() override {
        return new RazerMouse();
    }

    Keyboard* createKeyboard() override {
        return new RazerKeyboard();
    }
};

int main() {
    const std::string factory_name = "Logitech";

    Factory* factory = nullptr;

    if (factory_name == "Logitech") {
        factory = new LogitechFactory();
    } else if (factory_name == "Razer") {
        factory = new RazerFactory();
    }

    if (factory == nullptr) {
        std::cout << "Factory not found" << std::endl;
        return 1;
    }

    Mouse* mouse = factory->createMouse();
    Keyboard* keyboard = factory->createKeyboard();

    mouse->click();
    mouse->scroll();
    keyboard->type();
}