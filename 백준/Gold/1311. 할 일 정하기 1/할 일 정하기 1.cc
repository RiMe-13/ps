#include <iostream>
#include <cstring>

using namespace std;

int n;
const int INF = 1e9;
int cost[20][20];
int dp[20][1 << 20]; // dp[i][j] : 비트마스크 상태가 j일 때 i ~ 마지막 일까지 최소 비용

int solve(int idx, int mask) {
    if (idx == n) return 0;

    int& res = dp[idx][mask];
    if (res != -1) return res;

    res = INF;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) != 0) continue;
        res = min(res, cost[i][idx] + solve(idx + 1, mask | (1 << i)));
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    cout << solve(0, 0) << "\n";

    return 0;
}