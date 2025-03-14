#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n, m, w;
const int INF = 1e9;
vector<pair<pair<int, int>, int>> edge;
int dist[501];

bool BellmanFord() {
    for (int i = 1; i <= n; i++) {
        for (auto x : edge) {
            int s = x.first.first;
            int e = x.first.second;
            int t = x.second;

            if (dist[e] > dist[s] + t) {
                if (i == n) return true;
                else dist[e] = dist[s] + t;
            }
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for (int T = 0; T < tc; T++) {
        int s, e, t;
        edge.clear();
        cin >> n >> m >> w;
        for (int i = 1; i <= n; i++) dist[i] = INF;
        for (int i = 0; i < m; i++) {
            cin >> s >> e >> t;
            edge.push_back({{s, e}, t});
            edge.push_back({{e, s}, t});
        }
        for (int i = 0; i < w; i++) {
            cin >> s >> e >> t;
            edge.push_back({{s, e}, -t});
        }

        if (BellmanFord()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}