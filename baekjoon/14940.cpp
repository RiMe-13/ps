#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m;
int start_x, start_y;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int map[1001][1001];
int dist[1001][1001];
queue<pii> q;

bool isin(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int x, int y) {
    q.push({x, y});
    dist[x][y] = 0;

    while (!q.empty()) {
        pii v = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = v.first + dx[i];
            int new_y = v.second + dy[i];
            if (dist[new_x][new_y] != -1) continue;
            if (isin(new_x, new_y) && map[new_x][new_y] != 0) {
                dist[new_x][new_y] = dist[v.first][v.second] + 1;
                q.push({new_x, new_y});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                start_x = i, start_y = j;
            }
            dist[i][j] = -1;
        }
    }

    bfs(start_x, start_y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}