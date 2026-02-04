#include <iostream>
#include <deque>

using namespace std;

int idx, ans;
int n, m, x;
deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) dq.push_back(i);

    for (int i = 0; i < m; i++) {
        cin >> x;

        for (int j = 0; j < dq.size(); j++) {
            if (dq[j] == x) {
                idx = j;
                break;
            }
        }

        if (idx <= dq.size() / 2) {
            while (true) {
                if (dq.front() == x) {
                    dq.pop_front();
                    break;
                }
                ans++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            while (true) {
                if (dq.front() == x) {
                    dq.pop_front();
                    break;
                }
                
                ans++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    cout << ans << "\n";

    return 0;
}