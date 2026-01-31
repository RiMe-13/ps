#include <iostream>

using namespace std;

int t, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> a >> b;
        int n = 1;
        for (int i = 0; i < b; i++) n = (n * a) % 10;

        if (n == 0) cout << "10\n";
        else cout << n << "\n";
    }

    return 0;
}