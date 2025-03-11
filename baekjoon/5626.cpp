#include <iostream>

using namespace std;

int INF = 2147483647;
int h[10001];
int dp[10001][5001]; // dp[i][j] : i번째 열이의 높이가 j일 때 i번째까지 가능한 경우의 수
// dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		if (h[i] >= 5000) {
			cout << "0\n";
			return 0;
		}
	}

	if (h[0] > 0 || h[n] > 0) {
		cout << "0\n";
		return 0;
	}

	dp[1][0] = 1;
	h[1] = h[n] = 0;
	for (int i = 2; i <= n; i++) {
		if (h[i] == -1) {
			dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000007;
			for (int j = 1; j < 5000; j++) {
				dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007 + dp[i - 1][j + 1]) % 1000000007;
			}
		}
		else if (h[i] == 0) {
			dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000007;
		}
		else {
			dp[i][h[i]] = ((dp[i - 1][h[i] - 1] + dp[i - 1][h[i]]) % 1000000007 + dp[i - 1][h[i] + 1]) % 1000000007;
		}
	}

	cout << dp[n][0] << "\n";
	return 0;
}