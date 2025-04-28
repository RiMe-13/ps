#include <iostream>

using namespace std;

int v, e;
const int INF = 1e9;
int adj[401][401];

void floyd() {
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                if (adj[i][j] > adj[i][k] + adj[k][j]) adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i != j) adj[i][j] = INF;
        }
    }
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }

    floyd();

    int ans = INF;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i != j) ans = min(ans, adj[i][j] + adj[j][i]);
        }
    }

    if (ans == INF) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}