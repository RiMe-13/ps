#include <iostream>

using namespace std;

int n, m;
int arr[1000001];

int find(int a) {
	if (arr[a] == a) return a;
	else return arr[a] = find(arr[a]);
}

void u(int a, int b) {
	int aRoot = find(a);
	int bRoot = find(b);
	arr[aRoot] = bRoot;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) arr[i] = i;
	
	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd == 0) {
			u(a, b);
		}
		else {
			int aRoot = find(a);
			int bRoot = find(b);
			
			if (aRoot == bRoot) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	
	return 0;
}