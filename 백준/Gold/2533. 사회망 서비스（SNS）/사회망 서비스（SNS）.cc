#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[1000001][2]; // dp[i][0, 1] : i번째 노드가 얼리어답터(0)거나 아닐 때(1), 최소 얼리어답터 수
bool visited[1000001];
vector<int> adj[1000001];

void dfs(int x) {
    visited[x] = true;
    dp[x][0] = 1;

    for (int v : adj[x]) {
        if (visited[v]) continue;
        dfs(v);
        dp[x][1] += dp[v][0];
        dp[x][0] += min(dp[v][0], dp[v][1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cout << min(dp[1][0], dp[1][1]) << "\n";

    return 0;
}