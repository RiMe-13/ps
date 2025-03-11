#include <iostream>

using namespace std;

int pascal[31][31];

int combination(int n, int k)
{
    if (k == 0 || n == k) return 1;
    if (pascal[n][k] != 0) return pascal[n][k];
    return pascal[n][k] = combination(n - 1, k) + combination(n - 1, k - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		if (n > m - n) n = m - n;
		cout << combination(m, n) << "\n";
	}
	
	return 0;
}