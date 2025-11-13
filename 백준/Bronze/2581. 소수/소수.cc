#include <iostream>

using namespace std;

int n, m;
int sum, min_val = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        if (i == 1) continue;

        bool prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }

        if (!prime) continue;
        if (min_val == -1) min_val = i;
        sum += i;
    }

    if (min_val == -1) cout << "-1\n";
    else cout << sum << "\n" << min_val << "\n";

    return 0;
}