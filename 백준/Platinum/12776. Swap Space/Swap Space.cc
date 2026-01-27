#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int n;
pll v[1000001];

bool cmp(pll a, pll b) {
    ll aa = a.second - a.first, bb = b.second - b.first;

    if (aa >= 0 && bb < 0) return true;
    if (aa < 0 && bb >= 0) return false;
    if (aa < 0) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v, v + n, cmp);

    ll a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        ll aa = min(-a, -a + b - v[i].first);
        ll bb = -a + b - v[i].first + v[i].second;
        bb -= aa;
        aa = -aa;
        a = aa;
        b = bb;
    }
    cout << a << "\n";

    return 0;
}