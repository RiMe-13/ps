#include <iostream>
#include <numeric>

using namespace std;

bool arr[1000001];
int num[1000001];
int cnt;

void goldbach(int x) {
	int left = 0, right = cnt - 1;
	for (int i = 3; i <= x; i += 2) {
		if (arr[i] == false && arr[x - i] == false) {
			cout << x << " = " << i << " + " << x - i << "\n";
			return;
		}
	}
	cout << "Goldbach's conjecture is wrong.\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 2; i * i <= 1000000; i++) {
		if (arr[i] == false) {
			for (int j = i * i; j <= 1000000; j += i) {
				arr[j] = true;
			}
		}
	}
	
	while (true) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) break;
		
		goldbach(tmp);
	}
	
	return 0;
}