#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[1001][1001][2];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, pair<int, int>>> q;

bool isin(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs() {
    while (!q.empty()) {
        int broken = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (x == n - 1 && y == m - 1) return map[x][y][broken] + 1;

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (isin(new_x, new_y)) {
                if (map[new_x][new_y][0]) {
                    if (!broken) {
                        map[new_x][new_y][1] = map[x][y][0] + 1;
                        q.push({1, {new_x, new_y}});
                    }
                }
                else {
                    if (broken && map[new_x][new_y][broken]) continue;
                    map[new_x][new_y][broken] = map[x][y][broken] + 1;
                    q.push({broken, {new_x, new_y}});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            map[i][j][0] = c - '0';
        }
    }
    q.push({0, {0, 0}});
    cout << bfs() << "\n";

    return 0;
}