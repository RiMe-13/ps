#include <iostream>

using namespace std;

int n, m, ans;
int map[51][51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) map[i][j] = s[j] - '0';
    }
    
    int max_len = min(n, m);
    for (int len = 1; len <= max_len; len++) {
        for (int i = 0; i <= n - len; i++) {
            for (int j = 0; j <= m - len; j++) {
                int a = map[i][j];
                int b = map[i + len - 1][j];
                int c = map[i][j + len - 1];
                int d = map[i + len - 1][j + len - 1];

                if (a == b && b == c && c == d) ans = len;
            }
        }
    }
    cout << ans * ans << "\n";

    return 0;
}