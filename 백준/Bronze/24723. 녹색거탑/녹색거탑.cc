#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans = 1;
    cin >> n;

    for (int i = 0; i < n; i++) ans *= 2;
    cout << ans << "\n";

    return 0;
}