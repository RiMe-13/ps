#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, m, src, dst;
const int INF = 1e9;
int dist[1001];
vector<pii> adj[1001];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int src) {
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();

        if (dist[cur.second] < cur.first) continue;

        for (pii i : adj[cur.second]) {
            int next = i.second, weight = i.first;

            if (dist[next] > weight + cur.first) {
                dist[next] = weight + cur.first;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i <= n; i++) dist[i] = INF;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    cin >> src >> dst;

    dijkstra(src);

    cout << dist[dst] << "\n";

    return 0;
}