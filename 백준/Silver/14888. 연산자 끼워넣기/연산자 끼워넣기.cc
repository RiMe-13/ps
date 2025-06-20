#include <iostream>

using namespace std;

int n, max_val = -1e9, min_val = 1e9;
int arr[12], op[4];

void calc(int res, int idx) {
    if (idx == n) {
        if (res > max_val) max_val = res;
        if (res < min_val) min_val = res;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;
            if (i == 0) calc(res + arr[idx], idx + 1);
            else if (i == 1) calc(res - arr[idx], idx + 1);
            else if (i == 2) calc(res * arr[idx], idx + 1);
            else calc(res / arr[idx], idx + 1);
            op[i]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < 4; i++) cin >> op[i];

    calc(arr[0], 1);

    cout << max_val << "\n";
    cout << min_val << "\n";

    return 0;
}