#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;
vector<pii> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    pq.push(v[0].second);
    for (int i = 1; i < v.size(); i++) {
        if (v[i].first >= pq.top()) pq.pop();

        pq.push(v[i].second);
    }

    cout << pq.size() << "\n";

    return 0;
}