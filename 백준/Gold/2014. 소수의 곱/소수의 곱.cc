#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int k, n;
priority_queue<int, vector<int>, greater<int>> pq;
int arr[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
		arr[i] = tmp;
	}
	
	int m = 0;
	for (int i = 0; i < n ; i++) {
        while (pq.top() == m) pq.pop();
		for (int j = 0; j < k; j++) {
			if ((long long) pq.top() * (long long) arr[j] >= INT_MAX) break;
			pq.push(pq.top() * arr[j]);
		}
        m = pq.top();
        pq.pop();
	}
	cout << m << "\n";
	
	return 0;
}