#include <iostream>

using namespace std;

long long dp[1 << 10][101][10]; // dp[mask][n][i] : 비트마스크, 자릿수, 마지막 자리수 저장
const int MOD = 1e9;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    if (n < 10) cout << 0 << "\n";
    else {
        for (int i = 1; i < 10; i++) dp[1 << i][1][i] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                for (int mask = 0; mask < (1 << 10); mask++) {
                    if (j == 0) dp[mask | (1 << j)][i][j] += dp[mask][i - 1][j + 1] % MOD;
                    else if (j == 9) dp[mask | (1 << j)][i][j] += dp[mask][i - 1][j - 1] % MOD;
                    else dp[mask | (1 << j)][i][j] += (dp[mask][i - 1][j - 1] + dp[mask][i - 1][j + 1]) % MOD;
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < 10; i++) ans = (ans + dp[(1 << 10) - 1][n][i]) % MOD;
        cout << ans << "\n";
    }

    return 0;
}