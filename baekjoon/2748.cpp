#include <iostream>

using namespace std;

int n;

long long fibonacci(int n) {
	if (n <= 0) return 0;
	long long a = 1, b = 1, c = 1;
	for (int i = 3; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main() {
	cin >> n;

	cout << fibonacci(n) << endl;

	return 0;
}