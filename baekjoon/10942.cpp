#include <iostream>

using namespace std;

int n, m;
int a[2001];
bool dp[2001][2001]; // dp[i][j] : i ~ j까지 팰린드롬이 될 경우 true, 아닐 경우 false

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i] = true;
    }

    for (int i = 1; i < n; i++) if (a[i] == a[i + 1]) dp[i][i + 1] = true;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 2; j <= n; j++) {
            if (a[i] == a[j] && dp[i + 1][j - 1]) dp[i][j] = true;
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        if (dp[s][e]) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}