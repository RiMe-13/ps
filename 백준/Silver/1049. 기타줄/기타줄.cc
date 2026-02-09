#include <iostream>

using namespace std;

int n, m, min_set = 1e9, min_s = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        min_set = min(min_set, a);
        min_s = min(min_s, b);
    }

    int ans = min((n / 6 + 1) * min_set, min(n / 6 * min_set + n % 6 * min_s, n * min_s));
    cout << ans << "\n";

    return 0;
}