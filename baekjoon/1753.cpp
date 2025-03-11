#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E, K, INF = 1e9;
vector<pair<int, int>> adj[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[20001];
bool visited[20001];

void dijkstra(int K) {
	for (int i = 1; i <= V; i++) dist[i] = INF;
	dist[K] = 0;
	pq.push({0, K});
	
	while(!pq.empty()) {
		pair<int, int> tmp = pq.top();
		pq.pop();
		if (!visited[tmp.second]) {
			for (auto x : adj[tmp.second]) {
				if (dist[x.second] > dist[tmp.second] + x.first) dist[x.second] = dist[tmp.second] + x.first;
				pq.push({dist[x.second], x.second});
			}
			visited[tmp.second] = true;
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
	}
	
	dijkstra(K);
	
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	
	return 0;
}