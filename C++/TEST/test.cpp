#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    char* str = new char[2];
    char* str2 = new char[1];

    cout << &str << '\n' << &str2 << '\n';
    cout << str << '\n' << str2 << '\n';
}