#include <iostream>
#include <cstring>

using namespace std;

char star[3072][6144];

void solve(int x, int y, int n) {
	//기본 별찍기
	if (n == 3) {
		star[x][y] = '*';
		star[x + 1][y - 1] = '*';
		star[x + 2][y - 2] = '*';
		star[x + 2][y - 1] = '*';
		star[x + 2][y] = '*';
		star[x + 2][y + 1] = '*';
		star[x + 2][y + 2] = '*';
		star[x + 1][y + 1] = '*';
	}
	else {
		solve(x, y, n / 2);
		solve(x + n / 2, y - n / 2, n / 2);
		solve(x + n / 2, y + n / 2, n / 2);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;
	memset(star, ' ', sizeof(star));

	solve(0, n - 1, n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			cout << star[i][j];
		}
		cout << "\n";
	}
	return 0;
}