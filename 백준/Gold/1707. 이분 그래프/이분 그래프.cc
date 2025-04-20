#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int k, v, e;
int visited[20001];
vector<int> adj[20001];
queue<int> q;

void bfs(int s) {
    visited[s] = 1;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int v : adj[cur]) {
            if (visited[v]) continue;

            q.push(v);
            if (visited[cur] == 1) visited[v] = 2;
            else visited[v] = 1;
        }
    }
}

bool check() {
    for (int i = 1; i <= v; i++) {
        for (int v : adj[i]) {
            if (visited[i] == visited[v]) return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    for (int t = 0; t < k; t++) {
        cin >> v >> e;
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= v; i++) adj[i].clear();

        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= v; i++) {
            if (!visited[i]) bfs(i);
        }

        if (check()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}