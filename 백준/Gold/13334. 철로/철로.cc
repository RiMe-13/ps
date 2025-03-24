#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, d;
vector<pii> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int h, o;
        cin >> h >> o;
        if (h > o) swap(h, o);
        v.push_back({o, h});
    }
    cin >> d;

    sort(v.begin(), v.end());

    int s, e;
    int cnt = 0, max_val = 0;

    for (pii i : v) {
        e = i.first;
        s = e - d;

        while (!pq.empty() && pq.top() < s) {
            cnt--;
            pq.pop();
        }

        if (i.second >= s) {
            cnt++;
            pq.push(i.second);

            max_val = max(max_val, cnt);
        }
    }

    cout << max_val << "\n";

    return 0;
}