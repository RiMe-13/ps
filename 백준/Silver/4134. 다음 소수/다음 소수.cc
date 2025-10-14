#include <iostream>

using namespace std;

int t;
long long n;

bool prime(long long x) {
    if (x <= 1) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;

    for (long long i = 5; i * i <= x; i++) {
        if (x % i == 0) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> n;
        while (!prime(n)) n++;
        cout << n << "\n";
    }

    return 0;
}