#include <iostream>

using namespace std;

int n;
int min_x = 1e9, max_x = -1e9;
int min_y = 1e9, max_y = -1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        min_y = min(min_y, y);
        max_y = max(max_y, y);
    }

    cout << (max_x - min_x) * (max_y - min_y) << "\n";

    return 0;
}