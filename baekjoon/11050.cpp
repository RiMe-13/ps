#include <iostream>

using namespace std;

int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	int a = 1, b = 1;
	
	for (int i = 1; i <= k; i++) {
		a *= n;
		n--;
		b *= i;
	}
	
	cout << a / b << "\n";
	
	return 0;
}