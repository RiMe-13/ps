#include <iostream>

using namespace std;

long long pow[55];
long long a, b;

long long solve(long long x) {
    long long res = x & 1;

    for (int i = 54; i > 0; i--) {
        if (x & (1LL << i)) {
            res += pow[i - 1] + (x - (1LL << i) + 1);
            x -= 1LL << i;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    pow[0] = 1;
    for (int i = 1; i < 55; i++) pow[i] = 2 * pow[i - 1] + (1LL << i);
    cout << solve(b) - solve(a - 1) << "\n";

    return 0;
}