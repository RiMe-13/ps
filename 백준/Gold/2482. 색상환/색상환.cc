#include <iostream>

using namespace std;

int n, k;
const int MOD = 1000000003;
int dp[1001][1001]; // dp[i][j] : i가지 색 중에서 j개를 선택하는 경우의 수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    for (int i = 2; i < n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % MOD << "\n";

    return 0;
}