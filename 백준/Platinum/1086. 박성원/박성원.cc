#include <iostream>
#include <string>
#include <cstring>
#include <numeric>

using namespace std;

typedef long long ll;

string num[51];
ll n, k;
ll a[51], len[51], mul[51], dp[1 << 15][101];

void make(int k) {
    mul[0] = 1;
    for (int i = 1; i <= 50; i++) {
        mul[i] = mul[i - 1] * 10 % k;
    }
}

ll solve(int bit, ll x) {
    if (bit + 1 == (1 << n)) return x == 0;

    ll& res = dp[bit][x];
    if (~res) return res;

    res = 0;
    for (int i = 0; i < n; i++) {
        if (bit & (1 << i)) continue;
        res += solve(bit | (1 << i), (x * mul[len[i]] + a[i]) % k);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> n;
    ll f = 1;
    for (ll i = 0; i < n; i++) {
        cin >> num[i];
        f *= (i + 1);
    }
    cin >> k;

    for (int i = 0; i < n; i++) {
        len[i] = num[i].size();
        int t = 0;
        for (char s : num[i]) {
            t *= 10;
            t %= k;
            t += (s - '0');
            t %= k;
        }
        a[i] = t;
    }
    make(k);

    ll p = solve(0, 0), q = f;
    ll g = gcd(p, q);
    
    if (p == 0) cout << 0 << "/" << 1 << "\n";
    else cout << p / g << "/" << q / g << "\n";

    return 0;
}