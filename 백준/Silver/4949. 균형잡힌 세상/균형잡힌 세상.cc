#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s;
stack<char> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        getline(cin, s);
        st = {};

        if (s == ".") break;
        bool flag = false;

        for (char c : s) {
            if (c == '(' || c == '[') st.push(c);
            else if (c == ')') {
                if (!st.empty() && st.top() == '(') st.pop();
                else {
                    flag = true;
                    break;
                }
            }
            else if (c == ']') {
                if (!st.empty() && st.top() == '[') st.pop();
                else {
                    flag = true;
                    break;
                }
            }
        }

        if (!flag && st.empty()) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}