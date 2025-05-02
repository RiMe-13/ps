#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int T, n, m, t;
int s, g, h, dist;
const int INF = 1e9;
int s_dist[2001], g_dist[2001], h_dist[2001];
vector<pii> adj[2001];
vector<int> cand;
priority_queue<pii> pq;

void dijkstra(int start, int a[]) {
    pq.push({0, start});
    a[start] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (pii v : adj[cur]) {
            if (a[v.first] > cost + v.second) {
                a[v.first] = cost + v.second;
                pq.push({-a[v.first], v.first});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        for (int i = 0; i < 2001; i++) {
            adj[i].clear();
            s_dist[i] = INF;
            g_dist[i] = INF;
            h_dist[i] = INF;
        }
        cand.clear();

        cin >> n >> m >> t;
        cin >> s >> g >> h;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        for (int i = 0; i < t; i++) {
            int tmp;
            cin >> tmp;
            cand.push_back(tmp);
        }

        dijkstra(s, s_dist);
        dijkstra(g, g_dist);
        dist = g_dist[h];
        dijkstra(h, h_dist);
        sort(cand.begin(), cand.end());
        for (int d : cand) {
            if (s_dist[d] == s_dist[g] + dist + h_dist[d] || s_dist[d] == s_dist[h] + dist + g_dist[d]) cout << d << " ";
        }
        cout << "\n";
    }

    return 0;
}