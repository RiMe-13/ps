#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, res;
int diff[300001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    if (n == 0) cout << res << "\n";
    else {
        for (int i = 0; i < n; i++) {
            cin >> diff[i];
        }

        sort(diff, diff + n);

        int idx = round(n * 0.15);
        double sum = 0;

        for (int i = idx; i < n - idx; i++) sum += diff[i];
        res = round(sum / (n - idx * 2));
        cout << res << "\n";
    }

    return 0;
}