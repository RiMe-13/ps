#include <iostream>
#include <algorithm>

using namespace std;

int INF = 1e9;
int n;
int w[17][17];
int dp[65536][17]; // dp[i][j] : i는 비트마스크 값, 해당 비트마스크 값에서 마지막에 j로 갔을 때 드는 최소 비용

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> w[i][j];
		}
	}

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 1; j <= n; j++) dp[i][j] = INF;
	}

	dp[1][1] = 0;

	for (int i = 2; i < (1 << n); i++) {
		for (int j = 1; j <= n; j++) {
			if ((i & (1 << (j - 1))) == 0) continue; // i status에서 j번째를 방문하지 않았다면 pass

			int v = i - (1 << (j - 1)); // v status는 i status 중에서 j번째 아직 방문 X (가장 마지막에 j번째를 방문)
			for (int k = 1; k <= n; k++) {
				if (w[k][j] == 0) continue; // k -> j 경로 없을 경우 pass
				dp[i][j] = min(dp[i][j], dp[v][k] + w[k][j]);
			}
		}
	}

	int min_val = INF;
	int v = (1 << n) - 1;
	for (int i = 2; i <= n; i++) {
		if (w[i][1] == 0) continue;
		min_val = min(min_val, dp[v][i] + w[i][1]);
	}

	cout << min_val << "\n";

	return 0;
}