#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int x = 2, y = 3;
    [=x](){
        cout << x << endl;
    }();
}