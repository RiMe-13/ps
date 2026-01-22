#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, n, k;
long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        while (k != 2 && a.size() % (k - 1) != 1) a.push_back(0);

        priority_queue<int, vector<int>, greater<int>> pq(a.begin(), a.end());

        ans = 0;

        while (pq.size() > 1) {
            int s = 0;
            for (int i = 0; i < k; i++) {
                if (pq.empty()) break;

                s += pq.top();
                pq.pop();
            }
            ans += s;
            pq.push(s);
        }

        cout << ans << "\n";
    }

    return 0;
}