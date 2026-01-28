#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, r1, x2, y2, r2, d, c1, c2, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        c1 = (r1 - r2) * (r1 - r2);
        c2 = (r1 + r2) * (r1 + r2);
        
        if (d == 0) {
            if (c1 == 0) cout << "-1\n";
            else cout << "0\n";
        }
        else if (d == c1 || d == c2) cout << "1\n";
        else if (c1 < d && d < c2) cout << "2\n";
        else cout << "0\n";
    }

    return 0;
}