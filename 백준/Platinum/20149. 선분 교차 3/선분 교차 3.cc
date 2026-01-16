#include <iostream>
#include <vector>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
vector<pll> v;

void intersect(pll a, pll b, pll c, pll d) {
    double px = (a.X * b.Y - a.Y * b.X) * (c.X - d.X) - (a.X - b.X) * (c.X * d.Y - c.Y * d.X);
    double py = (a.X * b.Y - a.Y * b.X) * (c.Y - d.Y) - (a.Y - b.Y) * (c.X * d.Y - c.Y * d.X);
    double p = (a.X - b.X) * (c.Y - d.Y) - (a.Y - b.Y) * (c.X - d.X);

    if (p == 0) {
        if (b == c && a <= c) cout << b.X << " " << b.Y << "\n";
        else if (a == d && c <= a) cout << a.X << " " << a.Y << "\n";
    }
    else {
        double x = px / p, y = py / p;

        cout << fixed;
        cout.precision(9);
        cout << x << " " << y << "\n";
    }
}

int ccw(pll a, pll b, pll c) {
    ll tmp = (a.X * b.Y + b.X * c.Y + c.X * a.Y) - (b.X * a.Y + c.X * b.Y + a.X * c.Y);

    if (tmp > 0) return 1;
    else if (tmp == 0) return 0;
    else return -1;
}

void solve(pll a, pll b, pll c, pll d) {
    int ans1 = ccw(a, b, c) * ccw(a, b, d);
    int ans2 = ccw(c, d, a) * ccw(c, d, b);

    if (ans1 == 0 && ans2 == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);

        if (a <= d && b >= c) {
            cout << "1\n";
            intersect(a, b, c, d);
        }
        else cout << "0\n";
    }
    else {
        if (ans1 <= 0 && ans2 <= 0) {
            cout << "1\n";
            intersect(a, b, c, d);
        }
        else cout << "0\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 4; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    solve(v[0], v[1], v[2], v[3]);

    return 0;
}