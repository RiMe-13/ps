#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int INF = 1e9;
int n, p, start = 0;
int adj[17][17];
int dp[65536];

int solve(int s) {
    int cnt = __builtin_popcount(s);
    if (cnt >= p) return 0;

    if (dp[s] != -1) return dp[s];

    dp[s] = INF;

    for (int i = 1; i <= n; i++) {
        if (!(s & (1 << (i - 1)))) continue;
        for (int j = 1; j <= n; j++) {
            if (s & (1 << (j - 1))) continue;
            dp[s] = min(dp[s], solve(s | (1 << (j - 1))) + adj[i][j]);
        }
    }

    return dp[s];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'Y') start |= (1 << i);
    }
    cin >> p;
    int ans = INF;
    ans = solve(start);

    if (p == 0) cout << "0\n";
    else if (ans == INF) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}