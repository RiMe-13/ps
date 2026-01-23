#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

struct cmp {
    bool operator()(pii a, pii b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first > b.first;
    }
};

int c, n, ans;
vector<int> chicken;
priority_queue<pii, vector<pii>, cmp> cow;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> c >> n;
    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;
        chicken.push_back(x);
    }
    sort(chicken.begin(), chicken.end());
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cow.push({a, b});
    }

    for (int i = 0; i < n; i++) {
        pii cur = cow.top();
        for (int j = 0; j < chicken.size(); j++) {
            if (chicken[j] >= cur.first && chicken[j] <= cur.second) {
                chicken.erase(chicken.begin() + j);
                ans++;
                break;
            }
        }
        cow.pop();
    }

    cout << ans << "\n";

    return 0;
}