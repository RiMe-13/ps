#include <iostream>

using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    if (k >= n) cout << "0\n";
    else {
        int ans = 0;

        while (true) {
            int cnt = 0;
            int tmp = n;

            while (tmp > 0) {
                if (tmp % 2) cnt++;
                tmp /= 2;
            }

            if (k >= cnt) break;

            n++;
            ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}