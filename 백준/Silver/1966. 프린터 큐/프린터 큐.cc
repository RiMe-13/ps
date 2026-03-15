#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int t, n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        queue<pii> q;
        priority_queue<int> pq;
        int cnt = 0;

        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            q.push({i, x});
            pq.push(x);
        }

        while (!q.empty()) {
            int idx = q.front().first;
            int imp = q.front().second;
            q.pop();

            if (pq.top() == imp) {
                pq.pop();
                cnt++;
                if (idx == m) {
                    cout << cnt << "\n";
                    break;
                }
            }
            else q.push({idx, imp});
        }
    }

    return 0;
}