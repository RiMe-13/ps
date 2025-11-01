#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

pll p1, p2, p3, p4;

int ccw(pll a, pll b, pll c) {
    ll ans = 0;
    ans += (a.first * b.second + b.first * c.second + c.first * a.second);
    ans -= (b.first * a.second + c.first * b.second + a.first * c.second);

    if (ans > 0) return 1;
    else if (ans == 0) return 0;
    else return -1;
}

int solve() {
    int v1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int v2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (v1 <= 0 && v2 <= 0) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    cin >> p3.first >> p3.second;
    cin >> p4.first >> p4.second;

    cout << solve() << "\n";

    return 0;
}