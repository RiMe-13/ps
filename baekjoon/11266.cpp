#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e, o = 1;
vector<int> adj[10001];
int order[10001]; // DFS 시의 방문 순서
bool cutv[10001]; // 단절점 여부

int dfs(int node, bool root) {
	order[node] = o++;
	int low = order[node];
	int child_cnt = 0;

	for (int c : adj[node]) {
		if (!order[c]) {
			child_cnt++;
			int child_low = dfs(c, false);

			if (!root && child_low >= order[node]) cutv[node] = true;
			low = min(low, child_low);
		}
		else low = min(low, order[c]);
	}

	if (root && child_cnt > 1) cutv[node] = true;

	return low;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= v; i++) {
		if (!order[i]) dfs(i, true);
	}
	int cnt = 0;
	for (int i = 1; i <= v; i++) {
		if (cutv[i]) cnt++;
	}
	cout << cnt << "\n";
	for (int i = 1; i <= v; i++) {
		if (cutv[i]) cout << i << " ";
	}
	cout << "\n";

	return 0;
}