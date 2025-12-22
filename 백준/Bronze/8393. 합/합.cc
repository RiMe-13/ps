#include <iostream>

using namespace std;

int n, sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) sum += i;
    cout << sum << "\n";

    return 0;
}