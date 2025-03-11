#include <iostream>
#include <algorithm>

using namespace std;

int INF = 2147483647;
int n, c;
int bulb[201];
int dp[201][201]; // dp[i][j] : i ~ j번째 전구까지 같은 색으로 만드는 데에 걸리는 최소 횟수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> bulb[i];
	}

	for (int i = 1; i <= n; i++) dp[i][i] = 0;

	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			//cout << "test: " << i << " " << j << "\n";
			dp[i][j] = INF;
			for (int k = i; k <= j - 1; k++) {
				int q = dp[i][k] + dp[k + 1][j];
				if (bulb[i] != bulb[k + 1]) q++;
				if (q < dp[i][j]) dp[i][j] = q;
			}
		}
	}

	cout << dp[1][n] << "\n";

	return 0;
}