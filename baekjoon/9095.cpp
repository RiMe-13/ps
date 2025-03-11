#include <iostream>

using namespace std;

int dp[12]; // dp[i] : i를 1, 2, 3의 합으로 나타내는 경우의 수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i <= 11; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    int t, n;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}