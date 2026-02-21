#include <iostream>

using namespace std;

int n, m;
int a[51][51], b[51][51];

void change(int x, int y) {
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (a[i][j] == 1) a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
}

int solve() {
    int ans = 0;

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (a[i][j] != b[i][j]) {
                change(i, j);
                ans++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) return -1;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            b[i][j] = c - '0';
        }
    }
    cout << solve() << "\n";

    return 0;
}