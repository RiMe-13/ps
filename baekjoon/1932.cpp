#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dp[501][501]; // dp[i][j] : (i, j)에 도달했을 때 얻을 수 있는 최대 합
int a[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	dp[1][1] = a[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) dp[i][j] = a[i][j] + dp[i - 1][j];
			else if (j == i) dp[i][j] = a[i][j] + dp[i - 1][j - 1];
			else dp[i][j] = a[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < dp[n][i]) max = dp[n][i];
	}

	cout << max << "\n";

	return 0;
}