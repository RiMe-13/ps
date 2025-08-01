#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, r, cnt = 1;
int visited[100001];
vector<int> adj[100001];
queue<int> q;

void bfs() {
    visited[r] = cnt++;
    q.push(r);

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for (int v : adj[x]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = cnt++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());

    bfs();

    for (int i = 1; i <= n; i++) cout << visited[i] << "\n";

    return 0;
}