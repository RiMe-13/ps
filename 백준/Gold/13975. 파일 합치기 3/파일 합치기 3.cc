#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int t, k;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> k;
        pq = {};
        for (int i = 0; i < k; i++) {
            int tmp;
            cin >> tmp;
            pq.push(tmp);
        }

        long long ans = 0;
        while (pq.size() > 1) {
            long long sum = pq.top();
            pq.pop();
            sum += pq.top();
            pq.pop();
            ans += sum;
            pq.push(sum);
        }
        cout << ans << "\n";
    }

    return 0;
}