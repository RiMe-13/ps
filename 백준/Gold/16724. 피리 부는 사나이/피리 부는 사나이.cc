#include <iostream>
#include <set>

using namespace std;

int parent[1000001];
int map[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[b] = a;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'U') map[i][j] = 0;
			else if (s[j] == 'D') map[i][j] = 1;
			else if (s[j] == 'L') map[i][j] = 2;
			else if (s[j] == 'R') map[i][j] = 3;
		}
	}
	for (int i = 0; i < n * m; i++) parent[i] = i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cur = m * i + j;
			int dir = map[i][j];
			int nx = i + dx[dir];
			int ny = j + dy[dir];
			int next = m * nx + ny;
			Union(next, cur);
		}
	}

	for (int i = 0; i < n * m; i++) find(i);
	set<int> s;
	for (int i = 0; i < n * m; i++) s.insert(parent[i]);

	cout << s.size() << "\n";

	return 0;
}