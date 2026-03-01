#include <iostream>

using namespace std;

int n, k;
int c[101];
int dp[10001]; // dp[k] : k원을 만드는 최소 개수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= k; i++) dp[i] = 1e9;

    for (int i = 1; i <= n; i++) {
        for (int j = c[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - c[i]] + 1);
        }
    }

    if (dp[k] == 1e9) cout << "-1\n";
    else cout << dp[k] << "\n";

    return 0;
}