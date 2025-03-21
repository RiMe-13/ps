#include <iostream>

using namespace std;

typedef pair<long long, long long> pll;
typedef long long ll;

int ccw(pll a, pll b, pll c) {
    ll res = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);

    if (res < 0) return -1;
    else if (res > 0) return 1;
    else return 0;
}

bool is_line(int a, int b, int c, int d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);

    return a <= d && b >= c;
}

bool intersection(pll p1, pll p2, pll p3, pll p4) {
    int c1 = ccw(p1, p2, p3);
    int c2 = ccw(p1, p2, p4);
    int c3 = ccw(p3, p4, p1);
    int c4 = ccw(p3, p4, p2);

    if (c1 * c2 == 0 && c3 * c4 == 0) {
        return is_line(p1.first, p2.first, p3.first, p4.first) && is_line(p1.second, p2.second, p3.second, p4.second);
    }

    return c1 * c2 <= 0 && c3 * c4 <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pll p1, p2, p3, p4;
    cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second;
    cout << intersection(p1, p2, p3, p4) << "\n";

    return 0;
}