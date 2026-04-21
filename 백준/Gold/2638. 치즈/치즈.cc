#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, m, ans;
int map[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pii> q;

bool isin(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m;
}

void dfs(int x, int y) {
    if (map[x][y] == 0) map[x][y] = -1;
    else return;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isin(nx, ny)) dfs(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> map[i][j];
    }

    dfs(1, 1);
    while (true) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= m; y++) {
                if (map[x][y] == 1) {
                    int cnt = 0;
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if (map[nx][ny] == -1) cnt++;
                    }

                    if (cnt > 1) q.push({x, y});
                }
            }
        }

        if (q.empty()) break;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            map[x][y] = -1;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (map[nx][ny] == 0) dfs(nx, ny);
            }
        }

        ans++;
    }

    cout << ans << "\n";

    return 0;
}