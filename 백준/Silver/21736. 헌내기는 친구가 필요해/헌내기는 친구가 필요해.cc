#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, m, cnt;
pii start;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char campus[601][601];
bool visited[601][601];
queue<pii> q;

bool isin(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> campus[i][j];
            if (campus[i][j] == 'I') start = {i, j};
        }
    }

    q.push(start);
    visited[start.first][start.second] = true;
    
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (isin(nx, ny) && !visited[nx][ny] && campus[nx][ny] != 'X') {
                q.push({nx, ny});
                visited[nx][ny] = true;
                if (campus[nx][ny] == 'P') cnt++;
            }
        }
    }

    if (cnt == 0) cout << "TT\n";
    else cout << cnt << "\n";

    return 0;
}