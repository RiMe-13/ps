#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
pair<int, int> jewerly[300001];
int c[300001];
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> jewerly[i].first >> jewerly[i].second;
    for (int i = 0; i < k; i++) cin >> c[i];
    sort(jewerly, jewerly + n);
    sort(c, c + k);

    int idx = 0;
    int sum = 0;

    for (int i = 0; i < k; i++) {
        while (idx < n && c[i] >= jewerly[idx].first) {
            pq.push(jewerly[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum << "\n";

    return 0;
}