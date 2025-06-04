#include <iostream>
#include <vector>

using namespace std;

int n, m;
const int INF = 1e9;
int dist[101][101];
int route[101][101];
vector<int> v;

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;

                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    route[i][j] = k;
                }
            }
        }
    }
}

void find_route(int s, int e) {
    if (route[s][e] == 0) {
        v.push_back(s);
        v.push_back(e);
        return;
    }

    find_route(s, route[s][e]);
    v.pop_back();
    find_route(route[s][e], e);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    floyd();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << "0 ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << 0;
            else {
                v.clear();
                find_route(i, j);
                cout << v.size() << " ";
                for (int k : v) cout << k << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}