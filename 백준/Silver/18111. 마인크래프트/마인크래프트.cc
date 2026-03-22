#include <iostream>

using namespace std;

int n, m, b, min_t = 1e9, min_h = 1e9;
int map[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> map[i][j];
    }

    for (int h = 0; h <= 256; h++) {
        int r = 0, s = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] > h) r += (map[i][j] - h);
                else if (map[i][j] == h) continue;
                else s += (h - map[i][j]);
            }
        }

        if (r + b >= s) {
            int tmp = 2 * r + s;
            if (min_t >= tmp) {
                min_t = tmp;
                min_h = h;
            }
        }
    }

    cout << min_t << " " << min_h << "\n";

    return 0;
}