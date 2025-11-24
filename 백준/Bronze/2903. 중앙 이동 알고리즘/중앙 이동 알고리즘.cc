#include <iostream>

using namespace std;

int n, d = 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n--) {
        d *= 2;
        d--;
    }
    cout << d * d << "\n";

    return 0;
}