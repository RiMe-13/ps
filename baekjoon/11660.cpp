#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[1025][1025];
int sum[1025][1025]; //sum[i][j] : (1, 1)에서 (i, j)까지의 합

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int tmp_sum = 0;
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			tmp_sum += arr[i][j];
			sum[i][j] = sum[i - 1][j] + tmp_sum;
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x1 - 1][y2] - sum[x2][y1 - 1] << "\n";
	}

	return 0;
}