#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int t, n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        priority_queue<int> max_pq;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        unordered_map<int, int> cnt;

        cin >> k;
        for (int i = 0; i < k; i++) {
            char cmd;
            cin >> cmd >> n;

            if (cmd == 'I') {
                min_pq.push(n);
                max_pq.push(n);
                cnt[n]++;
            }
            else {
                if (n == 1) {
                    if (!max_pq.empty()) {
                        cnt[max_pq.top()]--;
                        max_pq.pop();
                    }
                }
                else {
                    if (!min_pq.empty()) {
                        cnt[min_pq.top()]--;
                        min_pq.pop();
                    }
                }
                while (!min_pq.empty() && cnt[min_pq.top()] == 0) min_pq.pop();
                while (!max_pq.empty() && cnt[max_pq.top()] == 0) max_pq.pop();
            }
        }

        while (!min_pq.empty() && cnt[min_pq.top()] == 0) min_pq.pop();
        while (!max_pq.empty() && cnt[max_pq.top()] == 0) max_pq.pop();

        if (max_pq.empty() || min_pq.empty()) cout << "EMPTY\n";
        else cout << max_pq.top() << " " << min_pq.top() << "\n";
    }

    return 0;
}