#include <iostream>

using namespace std;

int x, n, a, b, sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        sum += a * b;
    }
    if (sum == x) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}