#include <iostream>

using namespace std;

int n, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n >= 0) {
        if (n % 5 == 0) {
            ans += (n / 5);
            cout << ans << "\n";
            return 0;
        }

        n -= 3;
        ans++;
    }

    cout << "-1\n";

    return 0;
}