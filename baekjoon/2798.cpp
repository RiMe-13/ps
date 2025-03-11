#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, res = -1;
    int c[101];
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || i == k || j == k) continue;
                int sum = c[i] + c[j] + c[k];
                if (sum <= m && sum > res) res = sum;
            }
        }
    }

    cout << res << "\n";

    return 0;
}