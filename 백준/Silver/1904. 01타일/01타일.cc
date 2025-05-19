#include <iostream>

using namespace std;

int n;
long long dp[1000001]; // dp[i] : 크기가 i인 2진 수열을 만들 수 있는 경우의 수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1] = 1, dp[2] = 2;
    cin >> n;
    for (int i = 3; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    cout << dp[n] % 15746 << "\n";

    return 0;
}