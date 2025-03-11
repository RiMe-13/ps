#include <iostream>

using namespace std;

int a[1001];
int dp[1001]; // dp[i] : i번째를 마지막으로 하는 가장 긴 수열의 길이
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= 1; j--) {
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(dp[i], ans);
    }
    cout << ans << "\n";

    return 0;
}