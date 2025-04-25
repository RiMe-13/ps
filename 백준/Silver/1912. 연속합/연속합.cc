#include <iostream>

using namespace std;

int n;
int a[100001];
int dp[100001]; // dp[i] : i번째 수를 포함하는 최대의 연속합

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = -2147483648;
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";

    return 0;
}