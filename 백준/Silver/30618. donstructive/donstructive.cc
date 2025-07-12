#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    for (i = 1; i <= n; i += 2) cout << i << " ";
    if (n % 2 == 0) i = n;
    else i = n - 1;
    for (i; i >= 1; i -= 2) cout << i << " ";
    cout << "\n";

    return 0;
}