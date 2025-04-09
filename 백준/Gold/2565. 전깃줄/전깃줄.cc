#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;
int dp[101]; // dp[i] : i번째까지 없앨 필요가 없는 전깃줄 개수 -> LIS
pii line[101]; // 전깃줄 연결 정보 저장

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> line[i].first >> line[i].second;
    }
    sort(line + 1, line + 1 + n);

    int max_val = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (line[i].second > line[j].second) dp[i] = max(dp[i], dp[j] + 1);
        }
        max_val = max(max_val, dp[i]);
    }
    cout << n - max_val << "\n";

    return 0;
}