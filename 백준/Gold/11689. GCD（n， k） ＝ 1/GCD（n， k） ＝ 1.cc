#include <iostream>

using namespace std;

long long n, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    ans = n;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i) continue;
        ans -= ans / i;
        while (n % i == 0) n /= i;
    }

    if (n > 1) ans -= ans / n;
    cout << ans << "\n";

    return 0;
}