#include <iostream>

using namespace std;

int n, m, ans;
int paper[501][501];
bool visited[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isin(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int cnt, int score) {
    if (cnt == 4) {
        ans = max(ans, score);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (isin(nx, ny) && !visited[nx][ny]) {
            if (cnt == 2) {
                visited[nx][ny] = true;
                dfs(x, y, cnt + 1, score + paper[nx][ny]); 
                visited[nx][ny] = false;
            }

            visited[nx][ny] = true;
            dfs(nx, ny, cnt + 1, score + paper[nx][ny]);
            visited[nx][ny] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> paper[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            dfs(i, j, 1, paper[i][j]);
            visited[i][j] = false;
        }
    }
    cout << ans << "\n";

    return 0;
}