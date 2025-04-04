#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
int item[31];
vector<int> l, r;

void make(vector<int>& v, int w, int i, int end) {
    if (w > c) return;
    if (i == end) {
        v.push_back(w);
        return;
    }

    make(v, w + item[i], i + 1, end);
    make(v, w, i + 1, end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> item[i];

    make(l, 0, 0, n / 2);
    make(r, 0, n / 2, n);

    sort(r.begin(), r.end());

    long long cnt = 0;
    for (int x : l) {
        cnt += upper_bound(r.begin(), r.end(), c - x) - r.begin();
    }

    cout << cnt << "\n";

    return 0;
}