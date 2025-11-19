#include <iostream>

using namespace std;

int a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;

        if (a == b && b == c) cout << "Equilateral\n";
        else if (a >= b + c || b >= a + c || c >= a + b) cout << "Invalid\n";
        else if (a == b || b == c || c == a) cout << "Isosceles\n";
        else cout << "Scalene\n";
    }

    return 0;
}