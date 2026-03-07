#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n, m, cnt, res = 1e9, idx;
bool visited[101];
vector<int> adj[101];

void bfs(int a, int b) {
    queue<pii> q;
    q.push({a, 0});
    visited[a] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int c = q.front().second;
        q.pop();

        if (cur == b) {
            cnt = c;
            break;
        }

        for (int i : adj[cur]) {
            if (!visited[i]) {
                q.push({i, c + 1});
                visited[i] = true;
            }
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

    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;

            memset(visited, false, sizeof(visited));
            cnt = 0;
            bfs(i, j);
            tmp += cnt;
        }
        if (res > tmp) {
            res = tmp;
            idx = i;
        }
    }

    cout << idx << "\n";

    return 0;
}