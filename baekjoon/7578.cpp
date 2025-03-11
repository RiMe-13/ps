#include <iostream>
#include <algorithm>

using namespace std;

int n;
int first_idx = 1;
int a[500001]; // A열에서의 i번째 기기의 고유번호
int b[1000001]; // a에서의 고유번호가 b열에서는 어디에 있는지 확인
long long tree[1050001]; // indexed tree

long long sum(int a, int b) {
	int left = first_idx + a, right = first_idx + b;
	long long res = 0;

	while (left <= right) {
		if (left % 2 == 1) {
			res += tree[left];
			left++;
		}
		if (right % 2 == 0) {
			res += tree[right];
			right--;
		}
		left /= 2;
		right /= 2;
	}

	return res;
}

void update(int i, int val) {
	int node = first_idx + i;
	tree[node] = val;
	while (node > 0) {
		node /= 2;
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		b[tmp] = i;
	}

	while (first_idx < n) first_idx *= 2;
	first_idx--;
	long long result = 0;
	for (int i = 1; i <= n; i++) {
		result += sum(b[a[i]], n);
		update(b[a[i]], 1);
	}

	cout << result << "\n";

	return 0;
}