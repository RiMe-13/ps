#include <iostream>

using namespace std;

int n, m;
int cnt;
int arr[10000];

void count() {
	int sum = 0;
	int right = 0, left = 0;
	while (right <= n) {
		if (sum == m) cnt++;
		if (sum >= m) {
			sum -= arr[left];
			left++;
		}
		else {
			sum += arr[right];
			right++;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	count();

	cout << cnt << endl;

	return 0;
}