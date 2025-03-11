#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int farm[51][51];
bool visited[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int t, m, n, k;
queue<pii> q;
queue<pii> q2;

bool isin(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void bfs(int x, int y) {
    q2 = {};
    q2.push({x, y});

    while (!q2.empty()) {
        pii v = q2.front();
        q2.pop();
        if (visited[v.first][v.second]) continue;
        visited[v.first][v.second] = true;

        for (int i = 0; i < 4; i++) {
            if (isin(v.first + dx[i], v.second + dy[i]) && farm[v.first + dx[i]][v.second + dy[i]]) {
                q2.push({v.first + dx[i], v.second + dy[i]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        memset(farm, 0, sizeof(farm));
        memset(visited, false, sizeof(visited));
        q = {};
        q2 = {};
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            farm[x][y] = 1;
            q.push({x, y});
        }
        int cnt = 0;
        while (!q.empty()) {
            pii v = q.front();
            q.pop();
            if (!visited[v.first][v.second]) {
                cnt++;
                bfs(v.first, v.second);
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}