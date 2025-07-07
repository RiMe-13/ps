#include <iostream>
#include <deque>

using namespace std;

int n, k;
long long a[100001];
long long sum[100001]; // i번째까지의 누적 합
long long dp[100001]; // i번째까지의 최대 합
deque<int> dq;

long long c(int i) {
    return dp[i - 1] - sum[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && dq.front() < i - k) dq.pop_front();
        while (!dq.empty() && c(dq.back()) <= c(i)) dq.pop_back();
        dq.push_back(i);
        dp[i] = sum[i] + c(dq.front());
        if (i <= k) dp[i] = max(dp[i], sum[i]);
    }
    cout << dp[n] << "\n";

    return 0;
}