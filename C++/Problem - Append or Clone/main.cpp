#include <iostream>
#include <string>

using namespace std;

unsigned dynamic_buildString(string text, const unsigned APPEND_COST, const unsigned CLONE_COST) {
    unsigned len = text.length();

    if (len == 1) {
        return APPEND_COST;
    } else {
        for (unsigned cloneLen = len / 2; cloneLen > CLONE_COST / APPEND_COST; cloneLen--) {
            string cloneString = text.substr(0, len - cloneLen);
            string clone = text.substr(len - cloneLen, len);

            if (cloneString.find(clone) != string::npos) {
                return dynamic_buildString(cloneString, APPEND_COST, CLONE_COST) + CLONE_COST;
            }
        }
        string appendString = text.substr(0, len - 1);

        return dynamic_buildString(appendString, APPEND_COST, CLONE_COST) + APPEND_COST;
    }
}

int main() {
    cout << dynamic_buildString("aa", 1, 2) << "\n";
    cout << dynamic_buildString("aaaa", 2, 3) << "\n";
    cout << dynamic_buildString("xzxpzxzxpq", 10, 11) << "\n";

    return 0;
}
