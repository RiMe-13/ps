#include <iostream>
#include <numeric>

using namespace std;

int t, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> a >> b;
        cout << a * b / gcd(a, b) << "\n";
    }

    return 0;
}