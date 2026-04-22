#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n, bx, by;
int res, cnt, sz = 2;
bool stop, eat;
bool visited[21][21];
int map[21][21];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool isin(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int x, int y, int size) {
    queue<pair<pii, int>> q;
    q.push({{x, y}, 0});
    visited[x][y] = true;
    int tmp;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;

        if (map[x][y] > 0 && map[x][y] < size && tmp == t) {
            if ((bx > x) || (bx == x && by > y)) {
                bx = x;
                by = y;
                continue;
            }
        }
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isin(nx, ny) && !visited[nx][ny]) {
                if (map[nx][ny] <= size) {
                    if (map[nx][ny] > 0 && map[nx][ny] < size && !eat) {
                        eat = true;
                        bx = nx;
                        by = ny;
                        tmp = t + 1;
                        res += tmp;
                    }
                    else {
                        q.push({{nx, ny}, t + 1});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                bx = i;
                by = j;
                map[i][j] = 0;
            }
        }
    }

    while (!stop) {
        memset(visited, false, sizeof(visited));
        bfs(bx, by, sz);
        if (eat) {
            eat = false;
            cnt++;
            map[bx][by] = 0;
            if (cnt == sz) {
                sz++;
                cnt = 0;
            }
        }
        else stop = true;
    }

    cout << res << "\n";

    return 0;
}