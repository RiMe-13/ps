#include <iostream>

using namespace std;

int fact(int n) {
    if (n == 0) return 1;

    int ans = 1;
    for (int i = n; i > 0; i--) ans *= i;

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << fact(n) << "\n";

    return 0;
}