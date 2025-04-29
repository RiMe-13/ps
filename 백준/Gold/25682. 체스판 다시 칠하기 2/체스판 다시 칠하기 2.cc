#include <iostream>
#include <cstring>

using namespace std;

int n, m, k;
char board[2001][2001];
int sum[2001][2001];

int change(char c) {
    memset(sum, 0, sizeof(sum));
    int val;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) val = board[i][j] != c;
            else val = board[i][j] == c;

            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + val;
        }
    }

    int res = 2147483647;

    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {
            int tmp = sum[i + k][j + k] - sum[i][j + k] - sum[i + k][j] + sum[i][j];
            res = min(res, tmp);
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    cout << min(change('B'), change('W')) << "\n";

    return 0;
}