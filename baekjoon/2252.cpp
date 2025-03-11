#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int a, b;
int in[32001];
vector<int> adj[32001];
queue<int> q;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		in[b]++;
	}
	
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) q.push(i);
	}
	
	for (int i = 1; i <= n; i++) {
		int x = q.front();
		
		cout << x << " ";
		q.pop();
		
		for (int y : adj[x]) {
			in[y]--;
			if (in[y] == 0) q.push(y);
		}
	}
	
	return 0;
}