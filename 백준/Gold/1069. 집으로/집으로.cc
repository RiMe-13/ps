#include <iostream>
#include <cmath>

using namespace std;

double x, y, d, t, ans = 9999;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> y >> d >> t;
    double dist = sqrt(x * x + y * y);
    ans = min(ans, dist);

    dist = abs(d - dist);
    ans = min(ans, dist + t);

    for (int i = 2; ; i++) {
        dist -= d;
        if (dist <= 0) {
            ans = min(ans, t * i);
            break;
        }
        ans = min(ans, abs(dist) + t * i);
    }
    
    cout << fixed;
    cout.precision(9);
    cout << ans << "\n";

    return 0;
}