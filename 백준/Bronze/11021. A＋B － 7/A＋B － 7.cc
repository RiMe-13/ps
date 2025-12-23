#include <iostream>

using namespace std;

int t, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cin >> a >> b;
        cout << "Case #" << tc << ": " << a + b << "\n";
    }

    return 0;
}