#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
bool visited[1001];
vector<int> adj[1001];
queue<int> q;

void bfs(int x) {
    q.push(x);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        if (visited[v]) continue;
        visited[v] = true;

        for (int i : adj[v]) {
            if (!visited[i]) q.push(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(i);
            cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}