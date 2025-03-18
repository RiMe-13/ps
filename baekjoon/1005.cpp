#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, k, w;
int d[1001];
int dp[1001]; // dp[i] : i번째 건물을 짓는데까지 걸리는 최소 시간
int indegree[1001];
vector<int> adj[1001];
queue<int> q;

void bfs() {
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            dp[i] = d[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int v : adj[cur]) {
            dp[v] = max(dp[v], dp[cur] + d[v]);
            if (--indegree[v] == 0) q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        memset(d, 0, sizeof(d));
        memset(dp, 0, sizeof(dp));
        memset(indegree, 0, sizeof(indegree));
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
            adj[i].clear();
        }
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            indegree[y]++;
        }

        bfs();

        cin >> w;
        cout << dp[w] << "\n";
    }

    return 0;
}