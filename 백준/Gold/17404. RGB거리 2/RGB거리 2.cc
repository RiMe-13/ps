#include <iostream>

using namespace std;

int cost[1001][3];
int dp[1001][3]; // dp[i][j] : i번째 집을 j번 색깔로 칠할 경우의 최소 비용
int n, ans = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) cin >> cost[i][j];
    }

    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if (i == j) dp[1][j] = cost[1][j];
            else dp[1][j] = 1e9;
        }

        for (int j = 2; j <= n; j++) {
            dp[j][0] = cost[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
            dp[j][1] = cost[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
            dp[j][2] = cost[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
        }

        for (int j = 0; j <= 2; j++) {
            if (i == j) continue;
            ans = min(ans, dp[n][j]);
        }
    }
    
    cout << ans << "\n";

    return 0;
}