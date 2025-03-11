#include <iostream>
#include <numeric>

using namespace std;

int n, k;
bool arr[1001];

int solve() {
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i * j > n) break;
			if (arr[i * j] == false) {
				cnt++;
				arr[i * j] = true;
			}
			if (cnt == k) return i * j;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	for (int i = 2; i <= n; i++) arr[i] = false;
	cout << solve() << "\n";
	
	return 0;
}