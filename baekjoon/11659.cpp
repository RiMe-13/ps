#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[100001];
int sum[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		cout << sum[b] - sum[a - 1] << "\n";
	}

	return 0;
}