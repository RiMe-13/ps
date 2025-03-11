#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][3]; // dp[i][0~2] : i번째 집을 0~2번 색깔로 칠할 경우의 최소 비용
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) cin >> dp[i][j];
    }

    for (int i = 2; i <= n; i++) {
        dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
    }

    int ans = min(min(dp[n][0], dp[n][1]), dp[n][2]);
    cout << ans << "\n";

    return 0;
}