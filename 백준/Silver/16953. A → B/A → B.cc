#include <iostream>

using namespace std;

int a, b, cnt = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    while (true) {
        if (b == a) {
            cout << cnt << "\n";
            break;
        }
        else if (b < a) {
            cout << "-1\n";
            break;
        }

        if (b % 2 == 0) {
            b /= 2;
            cnt++;
        }
        else if (b % 10 == 1) {
            b /= 10;
            cnt++;
        }
        else {
            cout << "-1\n";
            break;
        }
    }

    return 0;
}