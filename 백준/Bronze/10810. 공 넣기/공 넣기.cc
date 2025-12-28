#include <iostream>

using namespace std;

int n, m;
int i, j, k;
int a[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int x = 0; x < m; x++) {
        cin >> i >> j >> k;
        for (int y = i; y <= j; y++) a[y] = k;
    }
    for (int x = 1; x <= n; x++) cout << a[x] << " ";
    cout << "\n";

    return 0;
}