#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<int> adj[501];
bool visited[501];

bool dfs(int idx, int before) {
    visited[idx] = true;

    for (int v : adj[idx]) {
        if (v == before) continue;

        if (visited[v]) return false;
        if (!dfs(v, idx)) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    while (true) {
        cin >> n >> m;
        if (n == 0) break;

        for (int i = 0; i <= n; i++) adj[i].clear();
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dfs(i, 0)) cnt++;
        }

        if (cnt == 0) cout << "Case " << tc << ": No trees.\n";
        else if (cnt == 1) cout << "Case " << tc << ": There is one tree.\n";
        else cout << "Case " << tc << ": A forest of " << cnt << " trees.\n";

        tc++;
    }

    return 0;
}