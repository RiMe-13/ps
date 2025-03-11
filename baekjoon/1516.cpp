#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[501];
vector<int> rev[501];
queue<int> q;
int a[501];
int time[501];
int in[501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int num;
		cin >> num;
		while (num != -1) {
			adj[num].push_back(i);
			rev[i].push_back(num);
			in[i]++;
			cin >> num;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) q.push(i);
	}
	
	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		
		int max_time = 0;
		for (int y : rev[x]) {
			if (max_time < time[y]) max_time = time[y];
		}
		time[x] = a[x] + max_time;
		
		for (int y : adj[x]) {
			in[y]--;
			if (in[y] == 0) q.push(y);
		}
	}
	
	for (int i = 1; i <= n; i++) cout << time[i] << "\n";
	
	return 0;
}