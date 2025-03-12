#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

vector<pii> adj[10001];
bool visited[10001];
int n, res, endp;

void dfs(int s, int len) {
    if (visited[s]) return;

    visited[s] = true;
    if (res < len) {
        res = len;
        endp = s;
    }

    for (pii i : adj[s]) dfs(i.first, len + i.second);
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

    dfs(1, 0);

    res = 0;
    memset(visited, false, sizeof(visited));
    dfs(endp, 0);
    cout << res << "\n";

    return 0;
}