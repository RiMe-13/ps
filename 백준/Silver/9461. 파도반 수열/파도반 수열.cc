#include <iostream>

using namespace std;

int t;
long long dp[101];

long long p(int n) {
    if (n < 3) return dp[n];
    if (dp[n] == 0) dp[n] = p(n - 2) + p(n - 3);

    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1] = dp[2] = 1;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        cout << p(n) << "\n";
    }

    return 0;
}