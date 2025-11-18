#include <iostream>

using namespace std;

int a1, a2, a3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a1 >> a2 >> a3;
    if (a1 + a2 + a3 != 180) cout << "Error\n";
    else if (a1 == a2 && a2 == a3) cout << "Equilateral\n";
    else if (a1 == a2 || a2 == a3 || a3 == a1) cout << "Isosceles\n";
    else cout << "Scalene\n";

    return 0;
}