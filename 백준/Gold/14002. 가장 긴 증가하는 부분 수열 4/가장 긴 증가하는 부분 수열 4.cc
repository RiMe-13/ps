#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int first_idx = 1;
vector<pii> v;
int a[1001];
int dp[3001]; // dp[i] : a[i]를 마지막 원소로 하는 LIS의 길이, 근데 인덱스 트리를 곁들인..

int get_max(int a, int b) {
	int left = first_idx + a, right = first_idx + b;
	int res = 0;

	while (left <= right) {
		if (left % 2 == 1) {
			res = max(res, dp[left]);
			left++;
		}
		if (right % 2 == 0) {
			res = max(res, dp[right]);
			right--;
		}
		left /= 2;
		right /= 2;
	}

	return res;
}

void update(int i, int val) {
	int node = first_idx + i;
	dp[node] = val;
	while (node > 0) {
		node /= 2;
		dp[node] = max(dp[node * 2], dp[node * 2 + 1]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (first_idx < n) first_idx *= 2;
	first_idx--;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v.push_back({ a[i], -i });
	}

	sort(v.begin(), v.end());

	for (pii x : v) {
		int idx = x.second * (-1);
		int val = get_max(1, idx - 1) + 1;
		update(idx, val);
	}
	
	int node = 1;
	while (node <= first_idx) {
		if (dp[node] == dp[node * 2]) node *= 2;
		else node = node * 2 + 1;
	}
	vector<int> ans;
	ans.push_back(a[node - first_idx]);
	for (int i = node; i > first_idx; i--) {
		if (a[i - first_idx] < a[node - first_idx] && dp[node] - dp[i] == 1) {
			ans.push_back(a[i - first_idx]);
			node = i;
		}
	}

	cout << dp[1] << "\n";
	for (auto p = ans.rbegin(); p != ans.rend(); p++) {
		cout << *p << " ";
	}
	cout << "\n";

	return 0;
}