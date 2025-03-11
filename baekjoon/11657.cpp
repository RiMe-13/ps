#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int a, b, c;
int INF = 1e9;
vector<pair<int, int>> adj[501];
queue<int> q;
long long dist[501];
bool visited[501];

bool BellmanFord() {
	visited[1] = true;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			for (pair<int, int> x : adj[j]) {
				if (visited[j]) {
					int v = x.first;
					int w = x.second;
					if (dist[v] > dist[j] + w) dist[v] = dist[j] + w;
					q.push(v);
				}
			}
		}
		while (!q.empty()) {
			int k = q.front();
			q.pop();
			visited[k] = true;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (pair<int, int> x : adj[i]) {
			if (visited[i]) {
				int v = x.first;
				int w = x.second;
				if (dist[v] > dist[i] + w) return false;
			}
		}
	}
	
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	
	for (int i = 2; i <= N; i++) dist[i] = INF;
	
	bool ans = BellmanFord();
	
	if (ans) {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF) cout << -1 << "\n";
			else cout << dist[i] << "\n";
		}
	}
	else cout << -1 << "\n";
	
	return 0;
}