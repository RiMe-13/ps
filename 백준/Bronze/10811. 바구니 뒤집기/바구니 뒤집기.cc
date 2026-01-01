#include <iostream>

using namespace std;

int n, m;
int a[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i] = i;
    while (m--) {
        int x, y;
        cin >> x >> y;
        for (int i = x; i <= (x + y) / 2; i++) {
            swap(a[i], a[y - i + x]);
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";

    return 0;
}