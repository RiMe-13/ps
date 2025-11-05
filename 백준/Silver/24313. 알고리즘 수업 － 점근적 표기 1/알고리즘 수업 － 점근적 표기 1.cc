#include <iostream>

using namespace std;

int a1, a0, c, n0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a1 >> a0;
    cin >> c;
    cin >> n0;

    if (a1 * n0 + a0 <= c * n0 && a1 <= c) cout << "1\n";
    else cout << "0\n";

    return 0;
}