#include <iostream>

using namespace std;

int n, k;
int pascal[1003][1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	if (k > n - k) k = n - k;
	
	pascal[1][1] = 1;
	for (int i = 2; i <= n + 1; i++) {
		for (int j = 1; j <= i; j++) {
			pascal[i][j] = (pascal[i - 1][j - 1] % 10007 + pascal[i - 1][j] % 10007) % 10007;
			//cout << "test: " << i << " " << j << " " << pascal[i][j] << "\n";
			if (i == n + 1 && j == k + 1) {
				cout << pascal[i][j] << "\n";
				return 0;
			}
		}
	}
	
	return 0;
}