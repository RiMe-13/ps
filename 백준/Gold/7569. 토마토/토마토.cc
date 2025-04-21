#include <iostream>
#include <queue>

using namespace std;

struct pos {
    int z, x, y;
};

int n, m, h;
int tomato[101][101][101];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
queue<pos> q;

bool isin(int z, int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < h;
}

void bfs() {
    while(!q.empty()) {
        pos v = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nz = v.z + dz[i];
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];

            if (isin(nz, nx, ny) && tomato[nz][nx][ny] == 0) {
                tomato[nz][nx][ny] = tomato[v.z][v.x][v.y] + 1;
                q.push({nz, nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1) q.push({i, j, k});
            }
        }
    }

    bfs();

    int max_val = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (tomato[i][j][k] == 0) {
                    cout << "-1\n";
                    return 0;
                }
                max_val = max(max_val, tomato[i][j][k]);
            }
        }
    }
    cout << max_val - 1 << "\n";

    return 0;
}