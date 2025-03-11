#include <iostream>

using namespace std;

int n, m;
int a, b;
int INF = 1000000000;
int adj[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) adj[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a][b] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (adj[i][j] > adj[i][k] + adj[k][j]) adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (adj[i][j] != INF || adj[j][i] != INF) cnt++;
        }
        if (cnt == n - 1) result++;
    }

    cout << result << "\n";

    return 0;
}