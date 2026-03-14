#include <iostream>

using namespace std;

int t, h, w, n;
int x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> h >> w >> n;

        x = n % h;
        y = (n / h + 1);
        if (x == 0) {
            x = h;
            y = n / h;
        }
        
        cout << x * 100 + y << "\n";
    }

    return 0;
}