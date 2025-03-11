#include <iostream>

using namespace std;

int n, h;
int first_idx = 1;
int tree[2100000];

void sum(int x, int y) {
	int left = first_idx + x, right = first_idx + y;
	while (left <= right) {
		if (left % 2 == 1) {
			tree[left]++;
			left++;
		}
		if (right % 2 == 0) {
			tree[right]++;
			right--;
		}
		left /= 2;
		right /= 2;
	}
}

int get(int a) {
	int node = first_idx + a;
	int sum = 0;
	while (node > 0) {
		sum += tree[node];
		node /= 2;
	}
	
	return sum;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> h;
	while (first_idx < h) first_idx *= 2;
	first_idx--;
	
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		if (i % 2 == 1) {
			sum(1, tmp);
		}
		else {
			sum(h - tmp + 1, h);
		}
	}
	
	int min = 1000000;
	int min_cnt = 0;
	for (int i = 1; i <= h; i++) {
		int val = get(i);
		if (min > val) {
			min = val;
			min_cnt = 1;
		}
		else if (min == val) min_cnt++;
	}
	cout << min << " " << min_cnt << "\n";
	
	return 0;
}