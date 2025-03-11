#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 1e9;
int n;
int arr[100001];
int p[5][5];
int dp[100001][5][5]; // dp[i][l][r] : i + 1번째부터 끝까지 갈 때, 현재 왼발이 l에 있고 오른발이 r에 있을 때 드는 최소 비용

int play(int i, int left, int right) {
	if (i == n) return 0;
	if (left != 0 && right != 0 && left == right) return INF;

	if (dp[i][left][right]) return dp[i][left][right];

	return dp[i][left][right] = min(play(i + 1, arr[i + 1], right) + p[left][arr[i + 1]], play(i + 1, left, arr[i + 1]) + p[right][arr[i + 1]]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; ; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			n = i - 1;
			break;
		}
		arr[i] = tmp;
	}

	for (int i = 0; i <= 4; i++) p[i][i] = 1;
	for (int i = 1; i <= 4; i++) p[0][i] = 2;
	p[1][2] = p[1][4] = p[2][1] = p[2][3] = p[3][2] = p[3][4] = p[4][1] = p[4][3] = 3;
	p[1][3] = p[2][4] = p[3][1] = p[4][2] = 4;

	play(0, 0, 0);

	cout << dp[0][0][0] << "\n";

	return 0;
}