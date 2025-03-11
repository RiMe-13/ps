#include <iostream>
#include <algorithm>

using namespace std;

long long x, y;

int main() {
	cin >> x >> y;
	
	long long win = y * 100 / x;
	if (win >= 99) {
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	
	long long left = 0, right = 1000000000;
	
	while (left <= right) {
		long long mid = (left + right) / 2;
		int tmp_win = (y + mid) * 100 / (x + mid);
		if (tmp_win > win) {
			right = mid - 1;
		}
		else left = mid + 1;
	}

	cout << left << endl;

	return 0;
}