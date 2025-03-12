#include <iostream>
#include <queue>

int dp[100001]; // dp[i] : i에 도착하는 최소 시간
bool visited[100001];
int n, k;

using namespace std;

bool isin(int x) {
    return x >= 0 && x <= 100000;
}

void solve() {
    queue<int> q;
    dp[n] = 0;
    q.push(n);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == k) return;
        if (visited[v]) continue;
        visited[v] = true;

        if (isin(v - 1)) {
            dp[v - 1] = min(dp[v - 1], dp[v] + 1);
            q.push(v - 1);
        }
        if (isin(v + 1)) {
            dp[v + 1] = min(dp[v + 1], dp[v] + 1);
            q.push(v + 1);
        }
        if (isin(v * 2)) {
            dp[v * 2] = min(dp[v * 2], dp[v]);
            q.push(v * 2);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i <= 100000; i++) dp[i] = 1000000000;
    solve();
    cout << dp[k] << "\n";

    return 0;
}