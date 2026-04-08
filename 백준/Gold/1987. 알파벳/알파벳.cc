#include <iostream>

using namespace std;

int r, c, ans;
char map[21][21];
bool visited[26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isin(int x, int y) {
    return x >= 0 && x < r && y >= 0 && y < c;
}

void dfs(int x, int y, int cnt) {
    ans = max(ans, cnt);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (isin(nx, ny)) {
            if (!visited[map[nx][ny] - 'A']) {
                visited[map[nx][ny] - 'A'] = true;
                dfs(nx, ny, cnt + 1);
                visited[map[nx][ny] - 'A'] = false;
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cin >> map[i][j];
    }

    visited[map[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << ans << "\n";

    return 0;
}