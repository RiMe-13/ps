#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int parent[18][100001];
int min_w[18][100001];
int max_w[18][100001];
int height[100001];
bool visited[100001];
vector<pair<int, int>> adj[100001];
queue<int> q;

pair<int, int> LCA(int a, int b) {
	int a_min = 1e9, b_min = 1e9;
	int a_max = 0, b_max = 0;
	if (height[a] < height[b]) swap(a, b);
	
	for (int i = 17; i >= 0; i--) {
		if (height[a] - height[b] >= (1 << i)) {
			a_min = min(a_min, min_w[i][a]);
			a_max = max(a_max, max_w[i][a]);
			a = parent[i][a];
		}
	}
	
	if (a == b) {
		int min_val = min(a_min, b_min);
		int max_val = max(a_max, b_max);
		return {min_val, max_val};
	}
	for (int i = 17; i >= 0; i--) {
		if (parent[i][a] != parent[i][b]) {
			a_min = min(a_min, min_w[i][a]);
			a_max = max(a_max, max_w[i][a]);
			a = parent[i][a];
			
			b_min = min(b_min, min_w[i][b]);
			b_max = max(b_max, max_w[i][b]);
			b = parent[i][b];
		}
	}
	a_min = min(a_min, min_w[0][a]);
	a_max = max(a_max, max_w[0][a]);
	b_min = min(b_min, min_w[0][b]);
	b_max = max(b_max, max_w[0][b]);
	int min_val = min(a_min, b_min);
	int max_val = max(a_max, b_max);
	return {min_val, max_val};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int k = 0; k < 18; k++) {
		for (int i = 0; i <=n; i++) {
			min_w[k][i] = 1e9;
		}
	}
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	visited[1] = true;
	for (auto x : adj[1]) {
		q.push(x.first);
		parent[0][x.first] = 1;
		min_w[0][x.first] = x.second;
		max_w[0][x.first] = x.second;
		height[x.first] = 1;
		visited[x.first] = true;
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		for (auto y : adj[x]) {
			if (!visited[y.first]) {
				q.push(y.first);
				parent[0][y.first] = x;
				min_w[0][y.first] = y.second;
				max_w[0][y.first] = y.second;
				height[y.first] = height[x] + 1;
				visited[y.first] = true;
			}
		}
	}
	
	for (int k = 1; k <= 17; k++) {
		for (int i = 1; i <= n; i++) {
			parent[k][i] = parent[k - 1][parent[k - 1][i]];
			min_w[k][i] = min(min_w[k - 1][i], min_w[k - 1][parent[k - 1][i]]);
			max_w[k][i] = max(max_w[k - 1][i], max_w[k - 1][parent[k - 1][i]]);
		}
	}
	
	cin >> k;
	for (int i = 0; i < k; i++) {
		int d, e;
		cin >> d >> e;
		pair<int, int> res = LCA(d, e);
		cout << res.first << " " << res.second << "\n";
	}
	
	return 0;
}