#include <iostream>

using namespace std;

int n;
int a[1001];
int dp[1001]; // dp[i] : i번째 인덱스까지 증가하는 수열의 길이
int r_dp[1001]; // r_dp[i] : 뒤에서부터 i번째 인덱스까지 감소하는 수열의 길이

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j <= i; j++) {
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for (int i = n; i > 0; i--) {
        r_dp[i] = 1;
        for (int j = n; j >= i; j--) {
            if (a[j] < a[i]) r_dp[i] = max(r_dp[i], r_dp[j] + 1);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i] + r_dp[i] - 1);
    cout << ans << "\n";

    return 0;
}