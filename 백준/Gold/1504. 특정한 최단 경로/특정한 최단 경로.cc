#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int n, e, v1, v2;
const int INF = 1e9;
vector<pii> adj[801];
priority_queue<pii> pq;

void dijkstra(int s, vector<int>& dist) {
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int w = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (pii i : adj[cur]) {
            if (dist[i.first] > w + i.second) {
                dist[i.first] = w + i.second;
                pq.push({-dist[i.first], i.first});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    vector<int> dist1(n+1, INF), distv1(n+1, INF), distv2(n+1, INF);
    dijkstra(1, dist1);
    dijkstra(v1, distv1);
    dijkstra(v2, distv2);
    int d1 = (dist1[v1] == INF || distv1[v2] == INF || distv2[n] == INF) ? INF : dist1[v1] + distv1[v2] + distv2[n];
    int d2 = (dist1[v2] == INF || distv2[v1] == INF || distv1[n] == INF) ? INF : dist1[v2] + distv2[v1] + distv1[n];

    int ans = min(d1, d2);
    if (ans == INF) ans = -1;
    cout << ans << "\n";

    return 0;
}