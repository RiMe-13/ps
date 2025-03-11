#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int tomato[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int m, n;
queue<pii> q;

bool isin(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs() {
    while(!q.empty()) {
        pii v = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = v.first + dx[i];
            int new_y = v.second + dy[i];

            if (isin(new_x, new_y) && tomato[new_x][new_y] == 0) {
                tomato[new_x][new_y] = tomato[v.first][v.second] + 1;
                q.push({new_x, new_y});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) q.push({i, j});
        }
    }

    bfs();

    int max_val = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] == 0) {
                cout << "-1\n";
                return 0;
            }
            max_val = max(max_val, tomato[i][j]);
        }
    }
    cout << max_val - 1 << "\n";

    return 0;
}