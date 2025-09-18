#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, r;
int adj[301][301];
vector<pii> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
    for (int i = 1; i <= n; i++) adj[i][i] = 1;

    if (2 * (n - 1) >= n * (n - 1) / 2) {
        r = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (!adj[i][j]) {
                    ans.push_back({i, j});
                    adj[i][j] = adj[j][i] = 1;
                }
            }
        }
    }
    else {
        r = 2;
        for (int i = 1; i <= n; i++) {
            if (!adj[i][1]) {
                adj[i][1] = adj[1][i] = 1;
                ans.push_back({i, 1});
            }
        }
    }

    cout << ans.size() << "\n";
    cout << r << "\n";
    for (pii i : ans) {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}