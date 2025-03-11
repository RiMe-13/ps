#include <iostream>

using namespace std;

long long dp[101][21]; // dp[i][j] i번째 수까지 j를 만들어내는 경우의 수 
long long arr[101];
int n, result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		cin >> arr[i];
	}
	cin >> result;
	
	dp[1][arr[1]] = 1;
	for (int i = 2; i <= n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j + arr[i] <= 20) dp[i][j] += dp[i - 1][j + arr[i]];
			if (j - arr[i] >= 0) dp[i][j] += dp[i - 1][j - arr[i]];
		}
	}
	
	cout << dp[n - 1][result] << "\n";
	
	return 0;
}