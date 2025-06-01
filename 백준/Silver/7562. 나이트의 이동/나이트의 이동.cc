#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int t, l;
pii start, target;
int dist[301][301];
bool visited[301][301];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
queue<pii> q;

bool isin(int x, int y) {
    return x >= 0 && x < l && y >= 0 && y < l;
}

void bfs(pii v) {
    q.push(v);
    visited[v.first][v.second] = true;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        if (cur == target) {
            cout << dist[cur.first][cur.second] << "\n";
            return;
        }

        for (int i = 0; i < 8; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (isin(nx, ny) && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        memset(dist, 0, sizeof(dist));
        memset(visited, false, sizeof(visited));
        q = {};

        cin >> l;
        
        cin >> start.first >> start.second;
        cin >> target.first >> target.second;

        bfs(start);
    }

    return 0;
}