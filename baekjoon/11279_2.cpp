#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
				continue;
			}
			int out = pq.top();
			pq.pop();
			cout << out << "\n";
		}
		else {
			pq.push(tmp);
		}
	}
	
	return 0;
}