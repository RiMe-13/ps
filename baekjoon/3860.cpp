#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int INF = 1e9;
int w, h, g, e;
vector<pair<pair<int, int>, int>> adj[31][31]; // adj[x][y] : (x, y)에서 갈 수 있는 경로, {{x1, y2}, t}
bool is_tomb[31][31];
bool is_hole[31][31];
int dist[31][31];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isin(int x, int y) {
    return (x >= 0 && y >= 0 && x < w && y < h);
}

void graph() {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (is_tomb[i][j] || is_hole[i][j]) continue;
            if (i == w - 1 && j == h - 1) continue;

            for (int k = 0; k < 4; k++) {
                int next_x = i + dx[k];
                int next_y = j + dy[k];
                if (isin(next_x, next_y)) {
                    if (is_tomb[next_x][next_y]) continue;

                    adj[i][j].push_back({{next_x, next_y}, 1});
                }
            }
        }
    }
}

bool bellmanFord() {
    dist[0][0] = 0;

    for (int i = 0; i <= w * h - g; i++) {
        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                if (is_tomb[x][y]) continue;
                if (dist[x][y] == INF) continue;

                for (auto k : adj[x][y]) {
                    pii v = k.first;
                    int t = k.second;
                    int next_x = v.first;
                    int next_y = v.second;

                    if (dist[next_x][next_y] > dist[x][y] + t) {
                        if (i == w * h - g) return true;
                        dist[next_x][next_y] = dist[x][y] + t;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        for (int i = 0; i <= 30; i++) {
            for (int j = 0; j <= 30; j++) {
                adj[i][j].clear();
                dist[i][j] = INF;
            }
        }
        memset(is_tomb, false, sizeof(is_tomb));
        memset(is_hole, false, sizeof(is_hole));

        cin >> w >> h;
        if (w == 0 && h == 0) break;

        cin >> g;
        for (int i = 0; i < g; i++) {
            int x, y;
            cin >> x >> y;
            is_tomb[x][y] = true;
        }

        cin >> e;
        for (int i = 0; i < e; i++) {
            int x1, y1, x2, y2, t;
            cin >> x1 >> y1 >> x2 >> y2 >> t;
            is_hole[x1][y1] = true;
            adj[x1][y1].push_back({{x2, y2}, t});
        }

        graph();

        if (bellmanFord()) cout << "Never\n";
        else if (dist[w - 1][h - 1] == INF) cout << "Impossible\n";
        else cout << dist[w - 1][h - 1] << "\n";
    }

    return 0;
}