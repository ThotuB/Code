#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class plug {
   private:
    map<char, char> connect;

   public:
    plug(string plugConnects = "") {
        for (char c = 'A'; c <= 'Z'; c++) {
            connect[c] = c;
        }

        for (unsigned i = 0; i < plugConnects.size(); i += 3) {
            connect[plugConnects[i]] = plugConnects[i + 1];
            connect[plugConnects[i + 1]] = plugConnects[i];
        }
    }

    char operator[](char c) {
        return connect[c];
    }
};

class rotor {
   private:
    string name;
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string connect;
    string turnover;

    void rotate(unsigned nr) {
        // rotate right
        // connect = connect.substr(connect.size()-nr, nr) + connect.substr(0, connect.size()-nr);
        // alpha = alpha.substr(alpha.size()-nr, nr) + alpha.substr(0, alpha.size()-nr);
        // rotate left
        connect = connect.substr(nr) + connect.substr(0, nr);
        alpha = alpha.substr(nr) + alpha.substr(0, nr);
    }

   public:
    rotor() {}

    rotor(rotor& copyRotor) {
        name = copyRotor.name;
        connect = copyRotor.connect;
        turnover = copyRotor.turnover;
    }

    rotor(string _name, string _connect, string _turnover) {
        name = _name;
        connect = _connect;
        turnover = _turnover;
    }

    char operator[](char c) {
        return connect[c - 'A'];
    }

    bool turn(unsigned nr) {
        bool turnNext = (turnover.find(alpha[0]) != string::npos);
        rotate(nr);
        return turnNext;
    }

    friend ostream& operator<<(ostream& out, rotor& r) {
        out << r.name << " " << r.connect << " " << r.turnover;
        return out;
    }
};

class enigma {
   public:
    rotor reflector;
    rotor rotors[3];
    plug plugs;

    enigma(rotor _ref, rotor _rot1, rotor _rot2, rotor _rot3, unsigned _pos1, unsigned _pos2, unsigned _pos3, plug _plug) {
        reflector = _ref;

        rotors[0] = _rot1;
        rotors[0].turn(_pos1 - 1);

        rotors[1] = _rot2;
        rotors[0].turn(_pos2 - 1);

        rotors[2] = _rot3;
        rotors[0].turn(_pos3 - 1);

        plugs = _plug;
    }

    void turn() {
        if (!rotors[2].turn(1)) {
            return;
        }
        if (!rotors[1].turn(1)) {
            return;
        }
        rotors[0].turn(1);
    }

    string encode(string text) {
        string result = "";
        char resultChar;
        for (unsigned i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                continue;
            }
            if (i % 5 == 0 && i != 0) {
                result += ' ';
            }
            resultChar = plugs[text[i]];
            // cout << "Plug: " << resultChar << endl;
            resultChar = rotors[2][resultChar];
            // cout << "Rotor 3: " << resultChar << endl;
            resultChar = rotors[1][resultChar];
            // cout << "Rotor 2: " << resultChar << endl;
            resultChar = rotors[0][resultChar];
            // cout << "Rotor 1: " << resultChar << endl;
            resultChar = reflector[resultChar];
            // cout << "Reflector: " << resultChar << endl;
            resultChar = rotors[0][resultChar];
            // cout << "Rotor 1: " << resultChar << endl;
            resultChar = rotors[1][resultChar];
            // cout << "Rotor 2: " << resultChar << endl;
            resultChar = rotors[2][resultChar];
            // cout << "Rotor 3: " << resultChar << endl;
            resultChar = plugs[resultChar];
            // cout << "Plug: " << resultChar << endl
            //      << endl;

            //result += plugs[rotors[2][rotors[1][rotors[0][reflector[rotors[0][rotors[1][rotors[2][plugs[text[i]]]]]]]]]];

            result += resultChar;
            turn();
        }
        return result;
    }
};

int main() {
    plug p1("AV PM LS RG CO SE QW XU TB IN");

    rotor rotors[] = {{"I", "EKMFLGDQVZNTOWYHXUSPAIBRCJ", "Q"},
                      {"II", "AJDKSIRUXBLHWTMCQGZNPYFVOE", "E"},
                      {"III", "BDFHJLCPRTXVZNYEIWGAKMUSQO", "V"},
                      {"IV", "ESOVPZJAYQUIRHXLNFTGKDCMWB", "J"},
                      {"V", "VZBRGITYUPSDNHLXAWMJQOFECK", "Z"},
                      {"VI", "JPGVOUMFYQBENHZRDKASXLICTW", "ZM"},
                      {"VII", "NZJHGRCXMYSWBOUFAIVLPEKQDT", "ZM"},
                      {"VIII", "FKQHTLXOCBJSPDZRAMEWNIUYGV", "ZM"}};

    rotor reflectors[] = {{"ETW", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "-"},
                          {"Beta", "LEYJVCNIXWPBQMDRTAKZGFUHOS", "-"},
                          {"Gamma", "FSOKANUERHMBTIYCWLQPZXVGJD", "-"},
                          {"M4-B", "ENKQAUYWJICOPBLMDXZVFTHRGS", "-"},
                          {"M4-C", "RDOBJNTKVEHMLFCWZAXGYIPSUQ", "-"},
                          {"M3-B", "YRUHQSLDPXNGOKMIEBFZCWVJAT", "-"},
                          {"M3-C", "FVPJIAOYEDRZXWGCTKUQSBNMHL", "-"}};

    enigma enigga = {reflectors[5], rotors[0], rotors[1], rotors[2], 2, 4, 5, p1};

    string s;
    cin >> s;
    cout << enigga.encode("HELLO") << "\n";
}
