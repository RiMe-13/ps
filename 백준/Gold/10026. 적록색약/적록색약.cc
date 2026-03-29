#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n, cnt1, cnt2;
char map[101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isin(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int x, int y) {
    queue<pii> q;
    char color = map[x][y];
    visited[x][y] = true;
    q.push({x, y});

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (isin(nx, ny) && !visited[nx][ny] && map[nx][ny] == color) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> map[i][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bfs(i, j);
                cnt1++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'G') map[i][j] = 'R';
        }
    }
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bfs(i, j);
                cnt2++;
            }
        }
    }

    cout << cnt1 << " " << cnt2 << "\n";

    return 0;
}