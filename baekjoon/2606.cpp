#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[101];
vector<int> adj[101];
queue<int> q;
int n, k;

int bfs(int s) {
    visited[s] = true;
    for (int v : adj[s]) q.push(v);
    int cnt = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (!visited[v]) cnt++;
        visited[v] = true;

        for (int k : adj[v]) if (!visited[k]) q.push(k);
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << bfs(1) << "\n";

    return 0;
}