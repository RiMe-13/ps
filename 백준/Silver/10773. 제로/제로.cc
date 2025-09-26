#include <iostream>
#include <stack>

using namespace std;

int k, sum;
stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        if (n == 0) {
            sum -= st.top();
            st.pop();
        }
        else {
            sum += n;
            st.push(n);
        }
    }
    cout << sum << "\n";

    return 0;
}