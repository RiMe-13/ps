#include <iostream>
#include <vector>

using namespace std;

int n, r, q;
int dp[100001]; // dp[i] : 정점 i를 루트로 하는 서브트리 정점 수
bool visited[100001];
vector<int> adj[100001];

void dfs(int node, int parent) {
    visited[node] = true;

    for (int i : adj[node]) {
        if (visited[i]) continue;
        dfs(i, node);
    }

    if (parent != -1) dp[parent] += dp[node];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> q;
    for (int i = 1; i <= n; i++) dp[i] = 1;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(r, -1);
    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        cout << dp[u] << "\n";
    }

    return 0;
}