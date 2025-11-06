#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, m;
int indegree[101], dp[101][101];
bool basic[101];
vector<pii> adj[101];
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[b].push_back({a, c});
        indegree[a]++;
    }

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            basic[i] = true;
            q.push(i);
            dp[i][i] = 1;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto v : adj[cur]) {
            indegree[v.first]--;
            if (indegree[v.first] == 0) q.push(v.first);

            for (int j = 1; j <= n; j++) dp[v.first][j] += dp[cur][j] * v.second;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (basic[i]) cout << i << " " << dp[n][i] << "\n";
    }

    return 0;
}