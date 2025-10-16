#include <iostream>

using namespace std;

int n;

bool prime(int x) {
    if (x <= 1) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;

    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int cnt = 0;
        cin >> n;

        if (n == 0) break;

        for (int i = n + 1; i <= n * 2; i++) {
            if (prime(i)) cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}