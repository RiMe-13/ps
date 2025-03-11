#include <iostream>
#include <algorithm>

using namespace std;

int INF = 2147483647;
int m[101];
int c[101];
int dp[101][10001]; // dp[i][j] : i번째 앱까지에서, j의 비용으로 얻을 수 있는 최대 메모리

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> m[i];
	}
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
		sum += c[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j >= c[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + m[i]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= sum; i++) {
		if (dp[N][i] >= M) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}