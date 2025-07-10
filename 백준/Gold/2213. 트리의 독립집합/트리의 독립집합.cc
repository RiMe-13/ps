#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int w[10001];
int dp[10001][2]; // dp[i][0/1] : i번 노드가 독립집합에 포함되거나 되지 않을 때, 가중치의 최대합
bool visited[10001];
vector<int> adj[10001];
vector<int> path;

void dfs(int n) {
    visited[n] = true;

    dp[n][0] = 0;
    dp[n][1] = w[n];

    for (int i : adj[n]) {
        if (visited[i]) continue;

        dfs(i);

        dp[n][0] += max(dp[i][0], dp[i][1]);
        dp[n][1] += dp[i][0];
    }
}

void backtrack(int now, int prev) {
    if (dp[now][1] > dp[now][0] && !visited[prev]) {
        path.push_back(now);
        visited[now] = true;
    }

    for (int i : adj[now]) {
        if (i == prev) continue;
        backtrack(i, now);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    memset(visited, false, sizeof(visited));
    backtrack(1, 0);

    sort(path.begin(), path.end());

    cout << max(dp[1][0], dp[1][1]) << "\n";
    for (int i : path) cout << i << " ";
    cout << "\n"; 

    return 0;
}