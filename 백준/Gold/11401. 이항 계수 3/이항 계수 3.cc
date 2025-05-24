#include <iostream>

using namespace std;

static int MOD = 1000000007;

long long pow(long long a, long long m) {
    if (m == 0) return 1;

    long long tmp = pow(a, m / 2) % MOD;
    if (m % 2 == 1) return tmp * tmp % MOD * a % MOD;
    return tmp * tmp % MOD;
}

long long binomial(int n, int k) {
    if (k == 1 || k == n - 1) return n;
    if (k == 0 || k == n) return 1;

    long long a = 1, b = 1;
    for (int i = n; i >= n - k + 1; i--) a = (a * i) % MOD;
    for (int i = 1; i <= k; i++) b = (b * i) % MOD;
    long long ans = ((a % MOD) * pow(b , MOD - 2) % MOD) % MOD;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    cout << binomial(n, k) << "\n";

    return 0;
}