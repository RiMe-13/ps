#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, v;
vector<int> adj[1001];
bool visited[1001];
queue<int> q;

void bfs(int s) {
    q.push(s);
    visited[s] = true;
    cout << s << " ";

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int v : adj[cur]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                cout << v << " ";
            }
        }
    }
}

void dfs(int s) {
    visited[s] = true;
    cout << s << " ";

    for (int v : adj[s]) {
        if (!visited[v]) dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());

    dfs(v);
    cout << "\n";
    memset(visited, false, sizeof(visited));
    bfs(v);
    cout << "\n";

    return 0;
}