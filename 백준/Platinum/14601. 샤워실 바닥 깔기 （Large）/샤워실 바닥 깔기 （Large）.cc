#include <iostream>

using namespace std;

int k, x, y, cnt;
int map[257][257];

bool not_drain(int x, int y, int len) {
    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            if (map[i][j]) return false;
        }
    }

    return true;
}

void solve(int x, int y, int len) {
    cnt++;
    int half = len / 2;

    if (not_drain(x, y, half)) map[x + half - 1][y + half - 1] = cnt;
    if (not_drain(x + half, y, half)) map[x + half][y + half - 1] = cnt;
    if (not_drain(x, y + half, half)) map[x + half - 1][y + half] = cnt;
    if (not_drain(x + half, y + half, half)) map[x + half][y + half] = cnt;

    if (len == 2) return;

    solve(x, y, half);
    solve(x + half, y , half);
    solve(x, y + half, half);
    solve(x + half, y + half, half);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> x >> y;
    map[y - 1][x - 1] = -1;

    solve(0, 0, (1 << k));

    for (int i = (1 << k) - 1; i >= 0; i--) {
        for (int j = 0; j < (1 << k); j++) cout << map[i][j] << " ";
        cout << "\n";
    }

    return 0;
}