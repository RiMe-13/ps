#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, m;
int parent[17][40001];
int height[40001];
int dist[17][40001];
bool visited[40001];
vector<pii> adj[40001];
queue<pii> q;

int LCA(int a, int b) {
    if (height[a] < height[b]) swap(a, b);

    int sum = 0;
    for (int i = 16; i >= 0; i--) {
        if (height[a] - height[b] >= (1 << i)) {
            sum += dist[i][a];
            a = parent[i][a];
        }
    }

    if (a != b) {
        for (int i = 16; i >= 0; i--) {
            if (parent[i][a] != parent[i][b]) {
                sum += (dist[i][a] + dist[i][b]);
                a = parent[i][a];
                b = parent[i][b];
            }
        }
        sum += (dist[0][a] + dist[0][b]);
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    visited[1] = true;
    for (pii v : adj[1]) {
        q.push(v);
        parent[0][v.first] = 1;
        dist[0][v.first] = v.second;
        height[v.first] = 1;
        visited[v.first] = true;
    }
    while (!q.empty()) {
        pii x = q.front();
        q.pop();

        for (pii v : adj[x.first]) {
            if (!visited[v.first]) {
                q.push(v);
                parent[0][v.first] = x.first;
                dist[0][v.first] = v.second;
                height[v.first] = height[x.first] + 1;
                visited[v.first] = true;
            }
        }
    }

    for (int k = 1; k <= 16; k++) {
        for (int i = 1; i <= n; i++) {
            parent[k][i] = parent[k - 1][parent[k - 1][i]];
            dist[k][i] = dist[k - 1][i] + dist[k - 1][parent[k - 1][i]];
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }

    return 0;
}