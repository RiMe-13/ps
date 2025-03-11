#include <iostream>

using namespace std;

int n, cnt;
int visity[15];
int visitl[30];
int visitr[30];

// x번째 퀸을 x번째 줄에 놓는다!
void backtrack(int x) {
	if (x == n) {
		cnt++;
		return;
	}
	else {
		for (int y = 0; y < n; y++) {
			if (visity[y] == 0 && visitl[x - y + n] == 0 && visitr[x + y] == 0) {
				visity[y] = 1;
				visitl[x - y + n] = 1;
				visitr[x + y] = 1;
				backtrack(x + 1);
				visity[y] = 0;
				visitl[x - y + n] = 0;
				visitr[x + y] = 0;
			}
		}
		return;
	}
}

int main() {
	cin >> n;

	backtrack(0);

	cout << cnt << endl;

	return 0;
}