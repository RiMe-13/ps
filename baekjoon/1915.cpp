#include <iostream>
#include <queue>

using namespace std;

char arr[1001][1001];
int dp[1001][1001]; // dp[i][j] : (i ,j)를 사용해서 만들 수 있는 정사각형의 최대 변 길이
int max_l = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '1') {
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				if (max_l < dp[i][j]) max_l = dp[i][j];
			}
		}
	}

	cout << max_l * max_l << "\n";

	return 0;
}