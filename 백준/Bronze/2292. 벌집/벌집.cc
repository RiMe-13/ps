#include <iostream>

using namespace std;

int n, sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int i = 0;
    for (int sum = 2; sum <= n; i++) sum += 6 * i;

    if (n == 1) i = 1;
    cout << i << "\n";

    return 0;
}