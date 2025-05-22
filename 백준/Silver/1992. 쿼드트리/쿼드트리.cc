#include <iostream>

using namespace std;

int n;
string video[65];

void quadtree(int size, int x, int y) {
    char cur = video[x][y];

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (video[i][j] != cur) {
                cout << "(";
                quadtree(size / 2, x, y);
                quadtree(size / 2, x, y + size / 2);
                quadtree(size / 2, x + size / 2, y);
                quadtree(size / 2, x + size / 2, y + size / 2);
                cout << ")";
                return;
            }
        }
    }

    cout << cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> video[i];

    quadtree(n, 0, 0);
    cout << "\n";

    return 0;
}