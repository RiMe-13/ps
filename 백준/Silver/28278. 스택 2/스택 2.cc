#include <iostream>
#include <stack>

using namespace std;

int n;
stack<int> st;

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
            st.push(x);
        }
        else if (cmd == 2) {
            if (st.empty()) cout << "-1\n";
            else {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if (cmd == 3) {
            cout << st.size() << "\n";
        }
        else if (cmd == 4) {
            if (st.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if (cmd == 5) {
            if (st.empty()) cout << "-1\n";
            else cout << st.top() << "\n";
        }
    }

    return 0;
}