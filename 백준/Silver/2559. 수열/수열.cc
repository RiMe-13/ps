#include <iostream>

using namespace std;

int n, k;
int temp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    int max_val = 0, tmp = 0;
    for (int i = 1; i <= n; i++) {
        cin >> temp[i];

        if (i <= k) {
            tmp += temp[i];
            max_val += temp[i];
        }
        else {
            tmp += (temp[i] - temp[i - k]);
            max_val = max(max_val, tmp);
        }
    }
    cout << max_val << "\n";

    return 0;
}