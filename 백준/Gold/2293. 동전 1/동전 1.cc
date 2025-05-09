#include <iostream>

using namespace std;

int n, k;
int val[101];
int dp[10001]; // dp[k] : k원의 가치를 만드는 경우의 수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> val[i];

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = val[i]; j <= k; j++) {
            dp[j] += dp[j - val[i]];
        }
    }
    cout << dp[k] << "\n";

    return 0;
}