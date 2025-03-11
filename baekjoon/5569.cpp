#include <iostream>

using namespace std;

// dp[i][j][case] : (i, j)까지 case로 도달할 수 있는 경우의 수
// 제약사항 : 이전 두칸을 전부 봐야함. 
// case1: 오른쪽으로 두칸
// case2: 위, 오
// case3: 오, 위
// case4: 위로 두칸 
int dp[101][101][5];
int arr[1001][1001];
int w, h, mod = 100000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> w >> h;
	for (int i = 1; i <= w; i++) dp[i][1][1] = 1;
	for (int i = 1; i <= h; i++) dp [1][i][4] = 1;
	
	for (int i = 2; i <= w; i++) {
		for (int j = 2; j <= h; j++) {
			// 왼쪽에서 오는 것 
			dp[i][j][1] = (dp[i - 1][j][1] + dp[i - 1][j][2]) % mod;
			dp[i][j][2] = dp[i - 1][j][4];
			// 아래에서 오는 것 
			dp[i][j][3] = dp[i][j - 1][1];
			dp[i][j][4] = (dp[i][j - 1][3] + dp[i][j - 1][4]) % mod;
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= 4; i++) ans += dp[w][h][i];
	cout << ans % mod << "\n";
	
	return 0;
}