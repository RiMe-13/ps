#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long liq[5001];
long long ans[3];
long long res = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> liq[i];
    sort(liq, liq + n);

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            long long tmp = liq[i] + liq[left] + liq[right];
            if (abs(tmp) < res) {
                res = abs(tmp);
                ans[0] = liq[i];
                ans[1] = liq[left];
                ans[2] = liq[right];
            }

            if (tmp < 0) left++;
            else right--;
        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";

    return 0;
}