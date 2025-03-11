#include <iostream>

using namespace std;

int dp[1001][1001]; // dp[i][j]: n - 1번 산책로를 다니면서 (i, j) 교차로를 지나간 횟수 
int arr[1001][1001];
int h, w, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> h >> w >> n;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> arr[i][j];
		}
	}
	
	dp[1][1] = n - 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (i == 1 && j == 1) continue;
			dp[i][j] = dp[i - 1][j] / 2 + (i - 1 != 0 && dp[i - 1][j] % 2 == 1 && arr[i - 1][j] == 0) + dp[i][j - 1] / 2 + (j - 1 != 0 && dp[i][j - 1] % 2 == 1 && arr[i][j - 1] == 1);
		}
	}
	
	int i = 1, j = 1;
	while (i <= h && j <= w) {
		if (arr[i][j] == 0) {
			if (dp[i][j] % 2 == 0) i++;
			else j++;
		}
		else {
			if (dp[i][j] % 2 == 0) j++;
			else i++;
		}
	}
	
	cout << i << " " << j << "\n";
	
	return 0;
}