#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[1000000];
int sub_arr[1000000];

int max_height() {
	int x = 0, h = 0;
	for (int i = 1; i < n; i++) {
		h += sub_arr[i] * i;
		if (h >= m) {
			x = arr[i] + ((h - m) / i);
			return x;
		}
	}
	x = arr[n - 1] - ((m - h) / n);
	if ((m - h) % n != 0) x--;
	return x;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, greater<>()); // 내림차순 정렬

	// 차 배열 생성
	for (int i = 1; i < n; i++) {
		sub_arr[i] = arr[i - 1] - arr[i];
	}

	cout << max_height() << endl;

	return 0;
}