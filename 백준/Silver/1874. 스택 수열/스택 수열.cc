#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n, cnt = 1;
bool flag = true;
stack<int> st;
vector<char> res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (cnt <= x) {
            st.push(cnt++);
            res.push_back('+');
        }

        if (st.top() == x) {
            st.pop();
            res.push_back('-');
        }
        else flag = false;
    }

    if (flag) {
        for (char c : res) cout << c << "\n";
    }
    else cout << "NO\n";

    return 0;
}