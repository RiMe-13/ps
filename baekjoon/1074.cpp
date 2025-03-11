#include <iostream>
#include <cmath>

using namespace std;

int n, r, c;
int cnt;

void solve(int x, int y, int size) {
    if (r == x && c == y) {
        cout << cnt << "\n";
        return;
    }
    else if (r < x + size && c < y + size && r >= x && c >= y) {
        solve(x, y, size / 2);
        solve(x, y + size / 2, size / 2);
        solve(x + size / 2, y, size / 2);
        solve(x + size / 2, y + size / 2, size / 2);
    }
    else cnt += size * size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;

    solve(0, 0, (1 << n));

    return 0;
}