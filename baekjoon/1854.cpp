#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<long long, long long> pll;

int n, m, k;
int visited[1001]; // 해당 지점에 방문한 횟수
long long dist[1001]; // i번째 지점의 k번째 최단 경로
vector<pll> adj[1001]; // 인접 리스트
priority_queue<pll, vector<pll>, greater<pll>> pq;

void dijkstra(int x) {
	pq.push({ 0, x });

	while (!pq.empty()) {
		pll tmp = pq.top();
		pq.pop();
		visited[tmp.second]++;
		if (visited[tmp.second] <= k) {
			for (pll x : adj[tmp.second]) {
				pq.push({ tmp.first + x.first, x.second });
			}
		}
		if (visited[tmp.second] == k) dist[tmp.second] = tmp.first;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dist, -1, sizeof(dist));

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}

	dijkstra(1);

	for (int i = 1; i <= n; i++) cout << dist[i] << "\n";

	return 0;
}