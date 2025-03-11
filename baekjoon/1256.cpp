#include <iostream>
#include <string>

using namespace std;

long long pascal[201][201];

long long combination(int n, int k)
{
    if (k == 0 || n == k) return 1;
    if (pascal[n][k] != 0) return pascal[n][k];
    if (pascal[n - 1][k] == 1000000001 || pascal[n - 1][k - 1] == 1000000001) return pascal[n][k] = 1000000001;
    pascal[n][k] = combination(n - 1, k) + combination(n - 1, k - 1);
    if (pascal[n][k] >= 1000000001) return pascal[n][k] = 1000000001;
    return pascal[n][k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	if (combination(n + m, m) < k) {
		cout << -1;
		return 0;
	}
	
	string str = "";
	while (n >= 1 && m >= 1) {
		if (combination(n + m - 1, m) >= k || combination(n + m - 1, m) == 1000000001) {
			str += 'a';
			n--;
		}
		else {
			k -= combination(n + m - 1, m);
			str += 'z';
			m--;
		}
	}
	if (n == 0) {
		while (m >= 1) {
			str += 'z';
			m--;
		}
	}
	if (m == 0) {
		while (n >= 1) {
			str += 'a';
			n--;
		}
	}
	
	cout << str << "\n";
	
	return 0;
}