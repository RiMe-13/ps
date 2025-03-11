#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int v, e;
vector<int> adj[100001];
int visited[100001];
vector<pii> cut_e;

int dfs(int parent, int start, int order) {
    int res = order;
    visited[start] = order;

    for (int i = 0; i < adj[start].size(); i++) {
        int next = adj[start][i];
        if (parent == next) continue;

        if (!visited[next]) {
            int next_order = dfs(start, next, order + 1);
            if (next_order > visited[start]) cut_e.push_back({ min(start, next), max(start, next) });
            res = min(res, next_order);
        }
        else res = min(res, visited[next]);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= v; i++) sort(adj[i].begin(), adj[i].end());
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) dfs(0 , i, 1);
    }

    sort(cut_e.begin(), cut_e.end());
    cout << cut_e.size() << "\n";
    for (pii x : cut_e) cout << x.first << " " << x.second << "\n";

    return 0;
}