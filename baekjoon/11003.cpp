#include <iostream>
#include <deque>

using namespace std;

int n, l;
deque<pair<int, int>> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;

		while (!dq.empty() && dq.back().first > tmp) dq.pop_back();
		dq.push_back({ tmp, i });
		if (dq.front().second < i - l + 1) dq.pop_front();
		cout << dq.front().first << " ";
	}
	cout << "\n";

	return 0;
}