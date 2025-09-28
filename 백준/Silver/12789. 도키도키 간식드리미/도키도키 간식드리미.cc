#include <iostream>
#include <stack>

using namespace std;

int n, cnt = 1;
stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == cnt) cnt++;
        else st.push(tmp);

        while (!st.empty() && st.top() == cnt) {
            st.pop();
            cnt++;
        }
    }

    if (st.empty()) cout << "Nice\n";
    else cout << "Sad\n";

    return 0;
}