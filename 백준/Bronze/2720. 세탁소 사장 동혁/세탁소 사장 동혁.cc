#include <iostream>

using namespace std;

int t, c;
int q, d, n, p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        q = d = n = p = 0;
        cin >> c;

        if (c >= 25) {
            q = c / 25;
            c -= (q * 25);
        }
        if (c >= 10) {
            d = c / 10;
            c -= (d * 10);
        }
        if (c >= 5) {
            n = c / 5;
            c -= (n * 5);
        }
        if (c > 0) p = c;

        cout << q << " " << d << " " << n << " " << p << "\n";
    }

    return 0;
}