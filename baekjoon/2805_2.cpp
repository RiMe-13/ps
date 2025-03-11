#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[1000000];

int max_height() {
	long long left = 0, right = arr[n - 1];
	long long mid;
	int ans = 0;

	while (left <= right) {
		long long sum = 0;
		mid = (left + right) / 2;
		
		for (int i = 0; i < n; i++) {
			if (arr[i] - mid > 0) sum += arr[i] - mid;
		}
		
		if (sum >= m) {
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return ans;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cout << max_height() << endl;

	return 0;
}