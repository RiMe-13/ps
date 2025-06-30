#include <iostream>
#include <deque>

using namespace std;

int n;
deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if (cmd == 2) {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if (cmd == 3) {
            if (dq.empty()) cout << "-1\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (cmd == 4) {
            if (dq.empty()) cout << "-1\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (cmd == 5) {
            cout << dq.size() << "\n";
        }
        else if (cmd == 6) {
            if (dq.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if (cmd == 7) {
            if (dq.empty()) cout << "-1\n";
            else cout << dq.front() << "\n";
        }
        else if (cmd == 8) {
            if (dq.empty()) cout << "-1\n";
            else cout << dq.back() << "\n";
        }
    }

    return 0;
}