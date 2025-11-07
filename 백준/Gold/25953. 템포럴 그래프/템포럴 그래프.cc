#include <iostream>

using namespace std;

const int MAX = 1e9;
int n, t, m, s, e;
int dist[1001][10000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t >> m;
    cin >> s >> e;

    for (int i = 0; i < n; i++) dist[0][i] = MAX;
    dist[0][s] = 0;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n; j++) dist[i + 1][j] = dist[i][j];
        for (int j = 0; j < m; j++) {
            int x, y, w;
            cin >> x >> y >> w;
            dist[i + 1][y] = min(dist[i + 1][y], dist[i][x] + w);
            dist[i + 1][x] = min(dist[i + 1][x], dist[i][y] + w);
        }
    }

    if (dist[t][e] < MAX) cout << dist[t][e] << "\n";
    else cout << "-1\n";

    return 0;
}