#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[10001][2]; // dp[i][0/1] : i번 마을이 일반/우수 마을일 때 i번을 루트로 하는 서브트리의 인구수 최댓값
int a[10001];
bool visited[10001];
vector<int> adj[10001];

void dfs(int n) {
    visited[n] = true;

    dp[n][0] = 0;
    dp[n][1] = a[n];

    for (int i : adj[n]) {
        if (visited[i]) continue;

        dfs(i);

        dp[n][0] += max(dp[i][0], dp[i][1]);
        dp[n][1] += dp[i][0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    cout << max(dp[1][0], dp[1][1]) << "\n";

    return 0;
}