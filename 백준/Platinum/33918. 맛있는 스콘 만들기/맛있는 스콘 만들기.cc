#include <iostream>
#include <deque>

using namespace std;

typedef long long ll;
typedef pair<long, long> pll;

ll n, m, c, d, ans;
ll b[210], dp[210][25100];
deque<pll> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> c >> d;
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 1; i <= m; i++) dp[0][i] = m - abs(b[0] - i);

    ll a = d / c;
    for (ll i = 1; i < n; i++) {
        for (ll j = 1; j <= c; j++) {
            ll k;
            for (k = j; k <= m; k += c) {
                while (!dq.empty() && dq.front().second < k - 2 * a * c) dq.pop_front();
                while (!dq.empty() && dq.back().first <= dp[i - 1][k]) dq.pop_back();
                dq.push_back({dp[i - 1][k], k});

                if (k - a * c > 0) dp[i][k - a * c] = dq.front().first + m - abs(b[i] - (k - a * c));
            }

            for (ll t = k - a * c; t <= m; t += c) {
                if (t > 0 && t <= m) {
                    while (!dq.empty() && dq.front().second < t - a * c) dq.pop_front();
                    dp[i][t] = dq.front().first + m - abs(b[i] - t); 
                }
            }
            dq.clear();
        }
    }

    ans = dp[n - 1][1];
    for (int k = 1; k <= m; k++) ans = max(ans, dp[n - 1][k]);

    cout << ans << "\n";

    return 0;
}