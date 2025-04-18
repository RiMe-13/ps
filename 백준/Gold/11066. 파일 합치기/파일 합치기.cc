#include <iostream>

using namespace std;

int t, k;
const int INF = 2147483647;
int sum[501];
int dp[501][501]; // dp[i][j] : i~j번째까지 파일을 합칠 때의 최소 비용

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> k;
        for (int i = 1; i <= k; i++) {
            int a;
            cin >> a;
            sum[i] = sum[i - 1] + a;
        }
        for (int i = 1; i <= k; i++) dp[i][i] = 0;
        for (int l = 2; l <= k; l++) {
            for (int i = 1; i <= k - l + 1; i++) {
                int j = i + l - 1;
                dp[i][j] = INF;
                for (int k = i; k <= j - 1; k++) {
                    int q = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];
                    if (q < dp[i][j]) dp[i][j] = q;
                }
            }
        }
        cout << dp[1][k] << "\n";
    }
    
    return 0;
}