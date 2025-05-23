#include <iostream>

using namespace std;

int n;
int m_one, zero, one;
int paper[2188][2188];

void fold(int size, int x, int y) {
    bool same = true;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != paper[x][y]) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (!same) {
        fold(size / 3, x, y);
        fold(size / 3, x + size / 3, y);
        fold(size / 3, x + 2 * (size / 3), y);
        fold(size / 3, x, y + size / 3);
        fold(size / 3, x + size / 3, y + size / 3);
        fold(size / 3, x + 2 * (size / 3), y + size / 3);
        fold (size / 3, x, y + 2 * (size / 3));
        fold (size / 3, x + size / 3, y + 2 * (size / 3));
        fold (size / 3, x + 2 * (size / 3), y + 2 * (size / 3));
    }
    else {
        if (paper[x][y] == -1) m_one++;
        else if (paper[x][y] == 0) zero++;
        else one++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> paper[i][j];
    }

    fold(n, 0, 0);
    cout << m_one << "\n";
    cout << zero << "\n";
    cout << one << "\n";

    return 0;
}