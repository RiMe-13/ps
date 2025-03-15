#include <iostream>
#include <map>

using namespace std;

map<long long, long long> m;
const int MOD = 1000000007;

long long f(long long n) {
    if (m[n]) return m[n];

    long long res;
    if (n % 2 == 0) res = (f(n / 2) * (f(n / 2 + 1) + f(n / 2 - 1))) % MOD;
    else res = ((f((n + 1) / 2) * f((n + 1) / 2)) % MOD) + ((f((n - 1) / 2) * f((n - 1) / 2)) % MOD) % MOD;

    return m[n] = res % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    m[0] = 0;
    m[1] = m[2] = 1;
    cout << f(n) << "\n";

    return 0;
}