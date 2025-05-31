#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, m;
int map[101][101];
bool visited[101][101];
int dist[101][101];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pii> q;

bool isin(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int sx, int sy) {
    visited[sx][sy] = true;
    dist[sx][sy] = 1;
    q.push({sx, sy});

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (isin(nx, ny) && !visited[nx][ny] && map[nx][ny] == 1) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                q.push({nx, ny});
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
            char tmp;
            cin >> tmp;
            map[i][j] = tmp - '0';
        }
    }

    bfs(0, 0);

    cout << dist[n - 1][m - 1] << "\n";

    return 0;
}