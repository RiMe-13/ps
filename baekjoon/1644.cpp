#include <iostream>

using namespace std;

bool arr[4000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 2; i * i <= 4000000; i++) {
		if (arr[i] == false) {
			for (int j = i * i; j <= 4000000; j += i) {
				arr[j] = true;
			}
		}
	}
	
	int n;
	cin >> n;
	
	int left = 1, right = 2;
	int sum = right, cnt = 0;
	while (left <= right && right <= n) {
		if (sum <= n) {
			if (sum == n)cnt++;
			right++;
			while (arr[right]) right++;
			sum += right;
		}
		else {
			left++;
			while (arr[left]) left++;
			sum -= left;
		}
	}
	
	cout << cnt << "\n";
	
	return 0;
}