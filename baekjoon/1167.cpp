#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int v, max_node, max_dist;
vector<pii> adj[100001];
bool visited[100001];

void dfs(int x, int dist) {
    if (visited[x]) return;

    if (max_dist < dist) {
        max_dist = dist;
        max_node = x;
    }
    visited[x] = true;

    for (pii i : adj[x]) dfs(i.first, dist + i.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v;
    for (int i = 0; i < v; i++) {
        int a;
        cin >> a;
        while (true) {
            int b, c;
            cin >> b;
            if (b == -1) break;
            cin >> c;
            adj[a].push_back({b, c});
        }
    }

    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    max_dist = 0;
    dfs(max_node, 0);
    cout << max_dist << "\n";

    return 0;
}