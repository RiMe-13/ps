#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int a, b;
int parent[18][100001];
int height[100001];
bool visited[100001];
vector<int> adj[100001];
queue<int> q;

int LCA(int a, int b) {
	if (height[a] < height[b]) swap(a, b);
	
	for (int i = 17; i >= 0; i--) {
		if (height[a] - height[b] >= (1 << i)) a = parent[i][a];
	}
	
	if (a == b) return a;
	for (int i = 17; i >= 0; i--) {
		if (parent[i][a] != parent[i][b]) {
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	return parent[0][a];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// 그래프 입력 
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	visited[1] = true;
	// 트리 구성 
	for (int x : adj[1]) {
		q.push(x);
		parent[0][x] = 1;
		height[x] = 1;
		visited[x] = true;
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		for (int y : adj[x]) {
			if (!visited[y]) {
				q.push(y);
				parent[0][y] = x;
				height[y] = height[x] + 1;
				visited[y] = true;
			}
		}
	}
	// 2^k번째 조상 구하기 
	for (int k = 1; k <= 17; k++) {
		for (int i = 1; i <= n; i++) {
			parent[k][i] = parent[k - 1][parent[k - 1][i]];
		}
	} 
	// LCA 찾기 
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
	
	return 0;
}