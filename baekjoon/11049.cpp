#include <iostream>
#include <queue>

using namespace std;

int INF = 2147483647;
int arr[501];
int dp[501][501]; // dp[i][j] : i ~ j번째 행렬까지 곱했을 때의 최소 연산 횟수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int r, c;
		cin >> r >> c;
		if (i == 1) arr[0] = r;
		arr[i] = c;
	}

	for (int i = 1; i <= n; i++) dp[i][i] = 0;

	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			dp[i][j] = INF;
			for (int k = i; k <= j - 1; k++) {
				int q = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
				if (q < dp[i][j]) dp[i][j] = q;
			}
		}
	}

	cout << dp[1][n] << "\n";

	return 0;
}