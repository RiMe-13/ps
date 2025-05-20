#include <iostream>

using namespace std;

int n, cnt1, cnt2;
int dp[41];

int fib(int n) {
    if (n == 1 || n == 2) {
        cnt1++;
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    fib(n);

    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        cnt2++;
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    cout << cnt1 << " " << cnt2 << "\n";

    return 0;
}