#include <iostream>

using namespace std;

int a, b, tmp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    tmp = b;
    while (tmp) {
        cout << a * (tmp % 10) << "\n";
        tmp /= 10;
    }
    cout << a * b << "\n";

    return 0;
}