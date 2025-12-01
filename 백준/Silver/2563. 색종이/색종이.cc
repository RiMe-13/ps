#include <iostream>

using namespace std;

int n, x, y, cnt;
bool a[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int k = 0; k < n; k++) {
        cin >> x >> y;
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                if (!a[i][j]) {
                    cnt++;
                    a[i][j] = true;
                }
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}