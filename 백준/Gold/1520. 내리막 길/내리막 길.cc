#include <iostream>

using namespace std;

int m, n;
int height[501][501];
int dp[501][501]; // dp[i][j] : (i, j)에서 출발해서 끝까지 갈 수 있는 경우의 수
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isin(int x, int y) {
    return x > 0 && x <= m && y > 0 && y <= n;
}

int dfs(int x, int y) {
    if (x == m && y == n) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isin(nx, ny)) {
            if (height[nx][ny] < height[x][y]) dp[x][y] = dp[x][y] + dfs(nx, ny);
        }
    }
    
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> height[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(1, 1) << "\n";

    return 0;
}