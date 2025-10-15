#include <iostream>

using namespace std;

int n, m;

bool prime(int x) {
    if (x <= 1) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;

    for (int i = 5; i * i <= x; i++) {
        if (x % i == 0) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        if (prime(i)) cout << i << "\n";
    }

    return 0;
}