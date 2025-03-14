#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, m, x;
const int INF = 1e9;
vector<pii> adj[1001];
vector<pii> adj2[1001]; // 역방향 간선
int dist[1001];
int dist2[1001];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int x) {
    pq = {};
    dist[x] = 0;
    pq.push({0, x});

    while (!pq.empty()) {
        int time = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        for (pii i : adj[v]) {
            if (dist[i.first] > time + i.second) {
                dist[i.first] = time + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }
}

void dijkstra2(int x) {
    pq = {};
    dist2[x] = 0;
    pq.push({0, x});

    while (!pq.empty()) {
        int time = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        for (pii i : adj2[v]) {
            if (dist2[i.first] > time + i.second) {
                dist2[i.first] = time + i.second;
                pq.push({dist2[i.first], i.first});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;
    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
        dist2[i] = INF;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj2[b].push_back({a, c});
    }

    dijkstra(x);
    dijkstra2(x);

    int max_val = 0;
    for (int i = 1; i <= n; i++) {
        max_val = max(max_val, dist[i] + dist2[i]);
    }
    cout << max_val << "\n";

    return 0;
}