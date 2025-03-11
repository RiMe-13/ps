#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001][1001]; // dp[i][j] : i~j번째 카드가 있을 때 획득 가능한 최대 점수

int play(int left, int right, int turn) {
	if (left > right) return 0;
	if (dp[left][right]) return dp[left][right];

	if (turn % 2 == 1) return dp[left][right] = max(arr[left] + play(left + 1, right, turn + 1), arr[right] + play(left, right - 1, turn + 1));
	else return dp[left][right] = min(play(left + 1, right, turn + 1), play(left, right - 1, turn + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = 0;
			}
		}

		play(1, n, 1);
		
		cout << dp[1][n] << "\n";
	}

	return 0;
}