#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int n;
ll x, y;
pll p[10001];

int ccw(pll a, pll b, pll c) {
    ll tmp = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
    if (tmp > 0) return 1;
    else if (tmp == 0) return 0;
    else return -1;
}

int intersect(pll a, pll b, pll c, pll d) {
    int c1 = ccw(a, b, c), c2 = ccw(a, b, d), c3 = ccw(c, d, a), c4 = ccw(c, d, b);

    if (c1 * c2 == 0 && c3 * c4 == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);

        if (b < c || d < a) return 0;
        else return 1;
    }
    else if (c1 * c2 <= 0 && c3 * c4 <= 0) return 1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        p[i] = {x, y};
    }
    p[n] = p[0];

    for (int i = 0; i < 3; i++) {
        int cnt = 0;
        cin >> x >> y;
        pll X = {x , y}, Y = {x + 1000000007, y + 1};
        bool flag = false;

        for (int j = 0; j < n; j++) {
            cnt += intersect(X, Y, p[j], p[j + 1]);
            if (ccw(p[j], X, p[j + 1]) == 0) {
                if ((p[j] <= X && X <= p[j + 1]) || p[j + 1] <= X && X <= p[j]) {
                    flag = true;
                    break;
                }
            }
        }

        if (flag || (cnt & 1)) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}