#include <iostream>

using namespace std;

int n, m, k;
int first_idx = 1;
long long tree[2100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> k;
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
	
	for (int i = 0; i < m + k; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		// 수 변경
		if (a == 1) {
			tree[first_idx + b] = c;
			int node = first_idx + b;
			tree[node] = c;
			while (node > 0) {
				node /= 2;
				tree[node] = tree[node * 2] + tree[node * 2 + 1];
			}
		}
		// 구간 합 쿼리
		else {
			int left = first_idx + b, right = first_idx + c;
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
			cout << sum << "\n";
		} 
	}
	
	return 0;
}