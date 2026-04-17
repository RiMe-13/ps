#include <iostream>
#include <numeric>

using namespace std;

typedef long long ll;

ll MOD = 1000000007;
ll m, a, b, ans;

ll f(ll x, ll y){
	if(y == 1) return x;
	if(y % 2 == 1) return x * f(x, y - 1) % MOD;
	ll p = f(x, y / 2);
	return p * p % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b >> a;
        ll g = gcd(a, b);
        b /= g;
        a /= g;

        ans += a * f(b, MOD - 2) % MOD;
        ans %= MOD;
    }
    cout << ans << "\n";

    return 0;
}