#include <iostream>

using namespace std;

int v[20], n;

void citire();
void verif(int n, int x, int &ok, float &r);

int main() {
    int x, ok, r;
    citire();

    cin >> x;
    verif(n, x, ok, 0);

    if (ok == 0) cout << "nu exista";
    return 0;
}
void citire() {
    int i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> v[i];
    }
}
void verif(int n, int x, int &ok, float &r) {
    int i;
    ok = 0;
    if (n > 0) {
        for (i = 0; i <= n; i++) {
            if (v[i] == x) {
                ok = 1;
                r = r + 1;
            }
        }
    } else
        cout << r;
}