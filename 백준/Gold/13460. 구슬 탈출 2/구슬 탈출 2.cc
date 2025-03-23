#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

struct step {
    pii red;
    pii blue;
    int count;
};

int n, m;
char map[11][11];
bool visited[11][11][11][11]; // visited[rx][ry][bx][by] : 빨간공과 파란공이 방문했는지 확인
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<step> q;

void shift(int& x, int& y, int& dist, int& i) {
    while (map[x + dx[i]][y + dy[i]] != '#' && map[x][y] != 'O') {
        x += dx[i];
        y += dy[i];
        dist++;
    }
}

void bfs(pii r, pii b) {
    q.push({r, b, 0});
    visited[r.first][r.second][b.first][b.second] = true;

    while (!q.empty()) {
        step s = q.front();
        int rx = s.red.first, ry = s.red.second;
        int bx = s.blue.first, by = s.blue.second;
        int cnt = s.count;
        q.pop();

        if (cnt >= 10) break;

        for (int i = 0; i < 4; i++) {
            int nrx = rx, nry = ry;
            int nbx = bx, nby = by;
            int rc = 0, bc = 0, ncnt = cnt + 1;

            shift(nrx, nry, rc, i);
            shift(nbx, nby, bc, i);

            if (map[nbx][nby] == 'O') continue;
            if (map[nrx][nry] == 'O') {
                cout << ncnt << "\n";
                return;
            }

            if (nrx == nbx && nry == nby) {
                if (rc > bc) nrx -= dx[i], nry -= dy[i];
                else nbx -= dx[i], nby -= dy[i];
            }

            if (visited[nrx][nry][nbx][nby]) continue;
            visited[nrx][nry][nbx][nby] = true;
            q.push({{nrx, nry}, {nbx, nby}, ncnt});
        }
    }

    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    pii red, blue;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R') red = {i, j};
            else if (map[i][j] == 'B') blue = {i, j};
        }
    }
    bfs(red, blue);

    return 0;
}