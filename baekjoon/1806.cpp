#include <iostream>
#include <algorithm>

using namespace std;

int n, s;
int arr[100001];

int min_length() {
	int left = 0, right = 0;
	int min = 1000000;
	int sum = 0;
	
	while (right <= n) {
		if (sum >= s) {
			if (min >= right - left) {
				min = right - left;
			}
			sum -= arr[left];
			left++;
			if (left == right) {
				sum += arr[right];
				right++;
			}
		}
		else {
			sum += arr[right];
			right++;
		}
	}
	if (min == 1000000) return 0;
	return min;
}

int main() {
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << min_length() << endl;

	return 0;
}