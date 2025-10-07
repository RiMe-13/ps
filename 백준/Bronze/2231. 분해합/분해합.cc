#include <iostream>

using namespace std;

int n, res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i < n; i++) {
        int sum = 0, num = i;

        while (num) {
            sum += num % 10;
            num /= 10;
        }

        if (sum + i == n) {
            res = i;
            break;
        }
    }

    cout << res << "\n";

    return 0;
}