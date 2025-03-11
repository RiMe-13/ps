#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int s, d;
int INF = 1e9;
int adj[501][501];
int dist[501];
vector<int> path[501];
bool visited[501];
bool visited_rev[501];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
queue<int> q;

int dijkstra(int s, int d) {
	for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
        path[i].clear();
        visited_rev[i] = false;
    }
	pq = {};
    q = {};

	dist[s] = 0;
	pq.push({ 0, s });
	
	while (!pq.empty()) {
		pair<int, int> tmp = pq.top();
		pq.pop();
		
		if (tmp.second == d) break;
		
		if (!visited[tmp.second]) {
			int k = tmp.second;
			for (int i = 0; i < n; i++) {
				if (adj[k][i] != 0) {
					if (dist[i] > dist[k] + adj[k][i]) {
						dist[i] = dist[k] + adj[k][i];
                        path[i].clear();
                        path[i].push_back(k);
					}
                    else if (dist[i] == dist[k] + adj[k][i]) {
                        path[i].push_back(k);
                    }
					pq.push({ dist[i], i });
				}
			}
			visited[tmp.second] = true;
		}
	}

    q.push(d);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        if (!visited_rev[p]) {
            for (int x : path[p]) {
                adj[x][p] = 0;
                q.push(x);
            }
        }
        visited_rev[p] = true;
    }

	return dist[d];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				adj[i][j] = 0;
			}
		}

		if (n == 0 && m == 0) break;
		cin >> s >> d;
		for (int i = 0; i < m; i++) {
			int u, v, p;
			cin >> u >> v >> p;
			adj[u][v] = p;
		}

		int min_l = dijkstra(s, d);
		int tmp = dijkstra(s, d);

		if (tmp == INF) cout << "-1\n";
		else cout << tmp << "\n";
	}

	return 0;
}