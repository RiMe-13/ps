#include <iostream>

using namespace std;

int k, n, max_val;
int lan[10001];

int binarySearch() {
    long long left = 1, right = max_val;
    long long ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;
        for (int i = 0; i < k; i++) cnt += (long long) lan[i] / mid;

        if (cnt >= n) {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else right = mid - 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> lan[i];
        max_val = max(max_val, lan[i]);
    }
    cout << binarySearch() << "\n";

    return 0;
}