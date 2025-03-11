#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[100000];

int binarySearch(int x) {
	int left = 0;
	int right = n - 1;
	int pivot;

	while (left <= right) {
		pivot = (left + right) / 2;

		if (arr[pivot] == x) return 1;
		else if (arr[pivot] < x) left = pivot + 1;
		else right = pivot - 1;
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		cout << binarySearch(tmp) << "\n";
	}

	return 0;
}