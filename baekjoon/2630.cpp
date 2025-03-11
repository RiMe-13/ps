#include <iostream>

using namespace std;

int w_cnt, b_cnt;
int p[129][129];

void solve(int x, int y, int n) {
    int cnt = 0;

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (p[i][j]) cnt++;
        } 
    }

    if (!cnt) w_cnt++;
    else if (cnt == n * n) b_cnt++;
    else {
        solve(x, y, n / 2);
        solve(x, y + n / 2, n / 2);
        solve(x + n / 2, y, n / 2);
        solve(x + n / 2, y + n / 2, n / 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }
    solve(0, 0, n);
    cout << w_cnt << "\n" << b_cnt << "\n";

    return 0;
}