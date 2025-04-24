#include <iostream>

using namespace std;

int n;
const int MOD = 1000000000;
int dp[101][10]; // dp[i][j] : i번째 자리까지 이전 자리수가 j일 때의 계단수가 되는 경우의 수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) dp[i][j] = dp[i - 1][j + 1];
            else if (j == 9) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

            dp[i][j] %= MOD;
        }
    }

    int res = 0;
    for (int i = 0; i < 10; i++) res = (res + dp[n][i]) % MOD;
    cout << res << "\n";

    return 0;
}