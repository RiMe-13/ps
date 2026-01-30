#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, x1, y1, x2, y2, cx, cy, r, n;
    double dist = 0;

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int cnt = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> cx >> cy >> r;

            dist = sqrt((cx - x1) * (cx - x1) + (cy - y1) * (cy - y1));

            bool s = sqrt((cx - x1) * (cx - x1) + (cy - y1) * (cy - y1)) <= r;
            bool e = sqrt((cx - x2) * (cx - x2) + (cy - y2) * (cy - y2)) <= r;

            if (s != e) cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}