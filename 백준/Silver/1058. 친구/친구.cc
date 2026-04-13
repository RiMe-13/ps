#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n, max_f;
char map[51][51];
bool visited[51];

void bfs(int v) {
    memset(visited, false, sizeof(visited));
    queue<pii> q;
    q.push({v, 0});
    visited[v] = true;

    int f = 0;
    while (!q.empty()) {
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();

        if (d > 1) continue;
        for (int i = 0; i < n; i++) {
            if (map[cur][i] == 'Y' && !visited[i]) {
                visited[i] = true;
                f++;
                q.push({i, d + 1});
            }
        }
    }

    max_f = max(max_f, f);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> map[i][j];
    }
    for (int i = 0; i < n; i++) bfs(i);
    cout << max_f << "\n";

    return 0;
}