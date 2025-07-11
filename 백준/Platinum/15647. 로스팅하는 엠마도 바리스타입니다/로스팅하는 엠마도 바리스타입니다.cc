#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n;
pii parent[300001];
int cnt [300001]; // 서브트리 크기
long long down[300001];
long long dp[300001]; // dp[i] : i를 루트로 할 때 최단 거리들의 합
vector<pii> adj[300001];

void dfs(int v, int p) {
    cnt[v] = 1;
    for (auto& [u, w] : adj[v]) {
        if (u == p) continue;
        parent[u] = {v, w};
        dfs(u, v);
        cnt[v] += cnt[u];
        down[v] += down[u] + (long long) w * cnt[u];
    }
}

void solve(int v, int p) {
    for (auto& [u, w] : adj[v]) {
        if (u == p) continue;

        dp[u] = dp[v] + (long long) w * (n - 2 * cnt[u]);
        solve(u, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    parent[1] = {-1, 0};
    dfs(1, -1);
    dp[1] = down[1];
    solve(1, -1);

    for (int i = 1; i <= n; i++) cout << dp[i] << "\n";

    return 0;
}