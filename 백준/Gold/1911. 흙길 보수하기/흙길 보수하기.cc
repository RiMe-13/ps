#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, l;
vector<pii> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    int cur = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].first <= cur && cur < v[i].second) {
            int q = (v[i].second - cur) / l;
            int r = (v[i].second - cur) % l;

            ans += q;
            cur += l * q;

            if (r) {
                ans++;
                cur += l;
            }
        }
        else if (v[i].first > cur) {
            cur = v[i].first;
            i--;
        }
    }
    cout << ans << "\n";

    return 0;
}