#include <iostream>
#include <algorithm>

using namespace std;

int sum, a[5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + 5);

    cout << sum / 5 << "\n";
    cout << a[2] << "\n";

    return 0;
}