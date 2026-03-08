#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;

    sort(a, a + n);

    int s = 0, e = a[n - 1];
    int res;
    while (s <= e) {
        int sum = 0;
        int mid = (s + e) / 2;
        for (int i = 0; i < n; i++) sum += min(a[i], mid);

        if (m >= sum) {
            res = mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }

    cout << res << "\n";

    return 0;
}