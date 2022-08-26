#include <cstring>

class String {
public:
    String(const char* s) {
        strcpy(str, s);
    }

    // copy constructor
    String(const String& s) {
        strcpy(str, s.str);
    }

    // copy assignment
    String& operator=(const String& s) {
        if (this != &s) {
            strcpy(str, s.str);
        }
        return *this;
    }

    // move constructor
    String(String&& s) {
        strcpy(str, s.str);
        s.str = nullptr;
    }

    // move assignment
    String& operator=(String&& s) {
        if (this != &s) {
            strcpy(str, s.str);
            s.str = nullptr;
        }
        return *this;
    }

    ~String() {
        delete[] str;
    }

    // concatenation
    String operator+(const char* s) {
        String tmp(str);
        strcat(tmp.str, s);
        return tmp;
    }


private:
    char *str;
};

int main() {

}