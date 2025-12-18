#include <iostream>

using namespace std;

int a, b, c, p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    if (a == b && b == c) p = 10000 + a * 1000;
    else if (a == b) p = 1000 + a * 100;
    else if (b == c || a == c) p = 1000 + c * 100;
    else p = max(max(a , b), c) * 100;
    cout << p << "\n";

    return 0;
}