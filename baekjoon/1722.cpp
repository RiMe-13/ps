#include <iostream>
#include <string>

using namespace std;

int arr[21];
bool visited[21];

long long factorial(int n) {
	if (n < 2) return 1;
	return ((long long) n) * factorial(n - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	if (k == 1) {
		long long t;
		cin >> t;
		int min = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (visited[j]) continue;
				if (factorial(n - i - 1) < t) t -= factorial(n - i - 1);
				else {
					cout << j << " ";
					visited[j] = true;
					break;
				}
			}
		}
	}
	else {
		long long order = 1;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			for (int j = 1; j < arr[i]; j++) {
				if (!visited[j]) {
					order += factorial(n - i - 1);
				}
			}
			visited[arr[i]] = true;
		}
		
		cout << order;
	}
	
	return 0;
}