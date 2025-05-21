#include <iostream>

using namespace std;

int n, m, k;
int a[101][101], b[101][101], res[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    cin >> m >> k;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) cin >> b[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= m; l++) {
                res[i][j] += a[i][l] * b[l][j];
            }
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}