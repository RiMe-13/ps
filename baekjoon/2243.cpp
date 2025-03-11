#include <iostream>

using namespace std;

int n, cnt;
int first_idx = 1;
int tree[2100000];

int sum(int x) {
	int left = first_idx + 1, right = first_idx + x;
	long long sum = 0;
	while (left <= right) {
		if (left % 2 == 1) sum += tree[left++];
		if (right % 2 == 0) sum += tree[right--];
		left /= 2;
		right /= 2;
	}
	return sum;
}

void change(int idx, int val) {
	int node = first_idx + idx;
	tree[node] += val;
	while (node > 0) {
		node /= 2;
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int binarySearch(int x) {
	int left = 0, right = 1000000;
	int ans;
	while (left <= right) {
		int mid = (left + right) / 2;
		int result = sum(mid);
		//cout << "test: " << mid << " " << result << " " << x << "\n";
		if (result < x) {
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return ans + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	while (first_idx < 1000000) first_idx *= 2;
	first_idx--;
	
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b;
			int res = binarySearch(b);
			cout << res << "\n";
			change(res, -1);
		}
		else {
			cin >> b >> c;
			change(b, c);
			cnt += c;
		}
	}
	
	return 0;
}