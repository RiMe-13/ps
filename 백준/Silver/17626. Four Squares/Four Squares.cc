#include <iostream>

using namespace std;

int n;
int dp[50001]; // dp[i] : i를 표현하는 데 사용되는 제곱수의 최소 개수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j * j <= i; j++) dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
    cout << dp[n] << "\n";

    return 0;
}