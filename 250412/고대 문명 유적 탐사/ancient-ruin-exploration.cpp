#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int k, m;
int map[5][5];
int r_map[5][5];
int max_map[5][5];
bool visited[5][5];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<int> q; // 유적 벽면 숫자 저장

bool isin(int x, int y) {
    return x >= 0 && x < 5 && y >= 0 && y < 5;
}

void rotate(int sx, int sy, int cnt) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            r_map[i][j] = map[i][j];
        }
    }

    for (int k = 0; k < cnt; k++) {
        int tmp = r_map[sx][sy + 2];
        r_map[sx][sy + 2] = r_map[sx][sy];
        r_map[sx][sy] = r_map[sx + 2][sy];
        r_map[sx + 2][sy] = r_map[sx + 2][sy + 2];
        r_map[sx + 2][sy + 2] = tmp;
        
        tmp = r_map[sx + 1][sy + 2];
        r_map[sx + 1][sy + 2] = r_map[sx][sy + 1];
        r_map[sx][sy + 1] = r_map[sx + 1][sy];
        r_map[sx + 1][sy] = r_map[sx + 2][sy + 1];
        r_map[sx + 2][sy + 1] = tmp;
    }
}

int bfs() {
    int res = 0;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (visited[i][j]) continue;

            queue<pii> q, tr;
            q.push({i, j});
            tr.push({i, j});
            visited[i][j] = true;

            while (!q.empty()) {
                pii cur = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = cur.first + dx[k], ny = cur.second + dy[k];
                    if (isin(nx, ny) && r_map[nx][ny] == r_map[cur.first][cur.second] && !visited[nx][ny]) {
                        q.push({nx, ny});
                        tr.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }

            if (tr.size() >= 3) {
                res += tr.size();
                while (!tr.empty()) {
                    pii c = tr.front();
                    tr.pop();
                    r_map[c.first][c.second] = 0;
                }
            }
        }
    }

    return res;
}

void fill() {
    for (int j = 0; j < 5; j++) {
        for (int i = 4; i >= 0; i--) {
            if (map[i][j] == 0) {
                map[i][j] = q.front();
                q.pop();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> m;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }

    for (int K = 0; K < k; K++) {
        int max_val = 0;

        for (int cnt = 1; cnt < 4; cnt++) {
            for (int sy = 0; sy <= 2; sy++) {
                for (int sx = 0; sx <= 2; sx++) {
                    rotate(sx, sy, cnt);
                    int score = bfs();
                    if (max_val < score) {
                        max_val = score;
                        for (int i = 0; i < 5; i++) {
                            for (int j = 0; j < 5; j++) {
                                max_map[i][j] = r_map[i][j];
                            }
                        }
                    }
                }
            }
        }

        if (max_val == 0) break;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                map[i][j] = max_map[i][j];
            }
        }

        while (true) {
            fill();
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    r_map[i][j] = map[i][j];
                }
            }
            int tmp = bfs();
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    map[i][j] = r_map[i][j];
                }
            }
            if (tmp == 0) break;
            max_val += tmp;
        }

        cout << max_val << " ";
    }
    cout << "\n";

    return 0;
}