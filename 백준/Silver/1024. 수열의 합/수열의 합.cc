#include <iostream>

using namespace std;

int n, l;
bool flag;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l;

    for (int i = l; i <= 100; i++) {
        int t = i * (i - 1) / 2;
        int c = n - t;

        if (c < 0) continue;

        if (c % i == 0) {
            int start = c / i;

            while (i--) cout << start++ << " ";
            cout << "\n";
            flag = true;
            break;
        }
    }

    if (!flag) cout << "-1\n";

    return 0;
}