#include <iostream>
#include <algorithm>

using namespace std;

int a[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a[0] >> a[1] >> a[2];

    sort(a, a + 3);

    if (a[0] + a[1] <= a[2]) a[2] = a[0] + a[1] - 1;
    cout << a[0] + a[1] + a[2] << "\n";

    return 0;
}