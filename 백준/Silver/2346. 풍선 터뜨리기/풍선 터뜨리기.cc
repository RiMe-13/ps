#include <iostream>
#include <deque>

using namespace std;

typedef pair<int, int> pii;

int n;
deque<pii> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        dq.push_back({i, tmp});
    }

    while (!dq.empty()) {
        int cur = dq.front().second;
        cout << dq.front().first << " ";
        dq.pop_front();

        if (dq.empty()) break;

        if (cur > 0) {
            for (int i = 0; i < cur - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            cur *= -1;
            for (int i = 0; i < cur; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    cout << "\n";

    return 0;
}