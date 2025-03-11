#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, tmp_0, tmp_2;
    int min_dp[3], max_dp[3], arr[3];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[0] >> arr[1] >> arr[2];
        if (i == 0) {
            min_dp[0] = max_dp[0] = arr[0];
            min_dp[1] = max_dp[1] = arr[1];
            min_dp[2] = max_dp[2] = arr[2];
        }
        else {
            tmp_0 = max_dp[0];
            tmp_2 = max_dp[2];
            max_dp[0] = max(max_dp[0], max_dp[1]) + arr[0];
            max_dp[2] = max(max_dp[1], max_dp[2]) + arr[2];
            max_dp[1] = max(max(tmp_0, max_dp[1]), tmp_2) + arr[1];

            tmp_0 = min_dp[0];
            tmp_2 = min_dp[2];
            min_dp[0] = min(min_dp[0], min_dp[1]) + arr[0];
            min_dp[2] = min(min_dp[1], min_dp[2]) + arr[2];
            min_dp[1] = min(min(tmp_0, min_dp[1]), tmp_2) + arr[1];
        }
    }

    cout << max(max(max_dp[0], max_dp[1]), max_dp[2]) << " " << min(min(min_dp[0], min_dp[1]), min_dp[2]) << "\n";

    return 0;
}