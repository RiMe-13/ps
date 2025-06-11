#include <iostream>

using namespace std;

int c, n;
int cost[21], client[21];
int dp[100001]; // dp[i] : i원을 사용했을 때의 고객 수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> c >> n;
    for (int i = 1; i <= n; i++) cin >> cost[i] >> client[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 100000; j++) {
            if (j - cost[i] >= 0)
                dp[j] = max(dp[j], dp[j - cost[i]] + client[i]);
        }
    }

    for (int i = 1; i <= 100000; i++) {
        if (dp[i] >= c) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}