#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int n;
priority_queue<int> pq1; //작은 수를 넣는 pq
priority_queue<int, vector<int>, greater<int>> pq2; // 큰 수를 넣는 pq

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		
		if (pq1.size() == pq2.size()) pq1.push(tmp);
		else pq2.push(tmp);
		
		if (pq2.size() != 0 && pq1.top() > pq2.top()) {
			int t1 = pq1.top();
			int t2 = pq2.top();
			pq1.pop();
			pq2.pop();
			pq2.push(t1);
			pq1.push(t2);
		}
		
		cout << pq1.top() << "\n";
	}
	
	return 0;
}