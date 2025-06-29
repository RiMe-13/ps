#include <iostream>
#include <cmath>

using namespace std;

void solve(int n) {
    int len = pow(3, n - 1);

    if (n == 0) {
        cout << "-";
        return;
    }

    solve(n - 1);
    for (int i = 0; i < len; i++) cout << " ";
    solve(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        solve(n);
        cout << "\n";
    }

    return 0;
}