#include <iostream>
#include <algorithm>

using namespace std;

long long n, ans;
int max_val;
int a[6];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
        ans += a[i];
        max_val = max(max_val, a[i]);
    }

    if (n == 1) cout << ans - max_val << "\n";
    else {
        ans = 0;
        a[0] = min(a[0], a[5]);
        a[1] = min(a[1], a[4]);
        a[2] = min(a[2], a[3]);

        sort(a, a + 3);
        int s1 = a[0];
        int s2 = s1 + a[1];
        int s3 = s2 + a[2];

        ans += 4 * s3;
        ans += 4 * s2 * ((n - 2) + (n - 1));
        ans += s1 * (4 * (n - 1) * (n - 2) + (n - 2) * (n - 2));

        cout << ans << "\n";
    }

    return 0;
}