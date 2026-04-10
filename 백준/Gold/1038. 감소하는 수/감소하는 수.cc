#include <iostream>
#include <queue>

using namespace std;

int n;
long long dp[1000001];
queue<long long> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= 9; i++) {
        q.push(i);
        dp[i] = i;
    }

    if (n >= 0 && n <= 10) cout << n << "\n";
    else {
        int idx = 10;
        while (idx <= n && !q.empty()) {
            long long num = q.front();
            q.pop();

            int last = num % 10;
            for (int i = 0; i < last; i++) {
                q.push(num * 10 + i);
                dp[idx++] = num * 10 + i;
            }
        }

        if (idx >= n && dp[n] != 0) cout << dp[n] << "\n";
        else cout << "-1\n";
    }

    return 0;
}