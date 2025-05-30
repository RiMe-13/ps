#include <iostream>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

int n, height;
long long cnt;
stack<pii> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> height;

        int cnt_same = 1;
        while (!s.empty() && s.top().first < height) {
            cnt += s.top().second;
            s.pop();
        }

        if (!s.empty()) {
            if (s.top().first == height) {
                cnt += s.top().second;
                cnt_same = s.top().second + 1;
                if (s.size() > 1) cnt++;

                s.pop();
            }
            else cnt++;
        }

        s.push({height, cnt_same});
    }

    cout << cnt << "\n";

    return 0;
}