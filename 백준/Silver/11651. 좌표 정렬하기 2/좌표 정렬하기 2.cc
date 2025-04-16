#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;
pii a[100001];

bool cmp(pii p1, pii p2) {
    if (p1.second < p2.second) return true;
    else if (p1.second == p2.second && p1.first < p2.first) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) cout << a[i].first << " " << a[i].second << "\n";

    return 0;
}