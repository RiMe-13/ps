#include <iostream>

using namespace std;

int x, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x;
    while (x) {
        if (x % 2) ans++;
        x /= 2;
    }
    cout << ans << "\n";

    return 0;
}