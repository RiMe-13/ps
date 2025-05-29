#include <iostream>
#include <stack>

using namespace std;

int n;
int h[100001];
stack<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];

    long long res = 0;
    for (int i = 0; i < n; i++) {
            while (!s.empty() && h[i] < h[s.top()]) {
                int top = h[s.top()];
                s.pop();
                int len = i;
                
                if (!s.empty()) len = i - s.top() - 1;
                if (res < (long long) len * top) res = (long long) (len * top);
            }
            s.push(i);
        }

        while (!s.empty()) {
            long long top = h[s.top()];
            s.pop();
            int len = n;

            if (!s.empty()) len = n - s.top() - 1;
            res = max(res, len * top);
        }

        cout << res << "\n";

    return 0;
}