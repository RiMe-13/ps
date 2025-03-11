#include <iostream>

using namespace std;

int n, m;
int arr[100001];
long long sum[100001]; // sum[i] : i부터 루트까지 무게 차이의 합 

int find(int a) {
	if (arr[a] == a) return a;
	else {
		sum[arr[a]] += sum[find(arr[a])];
		sum[a] += sum[arr[a]];
		return arr[a] = find(arr[a]);
	}
}

void u(int a, int b, int w) {
	int aRoot = find(a);
	int bRoot = find(b);
	if (aRoot == bRoot) return;
	arr[aRoot] = bRoot;
	sum[aRoot] = (long long) w - sum[a] + sum[b];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		
		for (int i = 1; i <= n; i++) {
			arr[i] = i;
			sum[i] = 0;
		}
		
		for (int i = 0; i < m; i++) {
			char cmd;
			int a, b;
			cin >> cmd >> a >> b;
			if (cmd == '!') {
				int w;
				cin >> w;
				u(a, b, w);
			}
			else if (cmd == '?') {
				int aRoot = find(a);
				int bRoot = find(b);
				if (aRoot == bRoot) {
					cout << sum[a] - sum[b] << "\n";
				}
				else cout << "UNKNOWN\n";
			}
		}
	}
	
	return 0;
}