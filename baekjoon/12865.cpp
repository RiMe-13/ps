#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, k;
int dp[101][100001]; // dp[i][w] : i번째 물품까지에서 w만큼의 무게를 채웠을 때의 최대 가치
vector<pii> t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        t.push_back({w, v});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int w = t[i - 1].first;
            int v = t[i - 1].second;

            if (j < w) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], v + dp[i - 1][j - w]);
        }
    }

    cout << dp[n][k] << "\n";

    return 0;
}