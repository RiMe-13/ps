#include <iostream>

using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> k;

    int l = 1, r = k;
    while (l < r) {
        int mid = (l + r) / 2;
        int cnt = 0;

        for (int i = 1; i <= n; i++) cnt += min(n, mid / i);

        if (cnt < k) l = mid + 1;
        else r = mid;
    }

    cout << r << "\n";

    return 0;
}