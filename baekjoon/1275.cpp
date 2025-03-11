#include <iostream>

using namespace std;

int n, q;
int first_idx = 1;
long long tree[2100000];

long long sum(int x, int y) {
	if (x > y) return sum(y, x);
	int left = first_idx + x, right = first_idx + y;
	long long sum = 0;
	while (left <= right) {
		if (left % 2 == 1) {
			sum += tree[left];
			left++;
		}
		if (right % 2 == 0) {
			sum += tree[right];
			right--;
		}
		left /= 2;
		right /= 2;
	}
	return sum;
}

void change(int a, int b) {
	int node = first_idx + a;
	tree[node] = b;
	while (node > 0) {
		node /= 2;
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> q;
	while (first_idx < n) first_idx *= 2;
	first_idx--;
	// 리프노드 생성
	for (int i = 1; i <= n; i++) {
		long long tmp;
		cin >> tmp;
		tree[first_idx + i] = tmp;
	}
	// 트리 초기화
	for (int i = first_idx; i > 0; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	
	for (int i = 0; i < q; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		cout << sum(x, y) << "\n";
		change(a, b);
	}
	
	return 0;
}