#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, m;
int s, e;
const int INF = 1e9;
int dist[1001];
int route[1001];
vector<pii> adj[1001];
vector<int> route_v;
priority_queue<pii> pq;

void dijkstra() {
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cost) continue;

        for (pii i : adj[cur]) {
            int next = i.first;
            int n_cost = i.second;
            
            if (dist[next] > cost + n_cost) {
                route[next] = cur;
                dist[next] = cost + n_cost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) dist[i] = INF;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    cin >> s >> e;

    dijkstra();

    cout << dist[e] << "\n";
    int tmp = e;
    while (tmp) {
        route_v.push_back(tmp);
        tmp = route[tmp];
    }
    cout << route_v.size() << "\n";
    for (auto i = route_v.rbegin(); i != route_v.rend(); i++) cout << *i << " ";
    cout << "\n";

    return 0;
}