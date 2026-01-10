#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++) {
		for(int k = 0; k < n - i; k++) cout << " ";
		for(int k = 0; k < i * 2 - 1; k++) cout << "*";
		cout << "\n";	
	}

	for(int i = n - 1; i > 0; i--) {
		for(int k = 0; k < n - i; k++) cout << " ";
		for(int k = 0; k < i * 2 - 1; k++) cout << "*";
		cout << "\n";
	}

	return 0;
}