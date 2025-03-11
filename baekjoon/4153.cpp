#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;

        if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b) cout << "right\n";
        else cout << "wrong\n";
    }

    return 0;
}