#include <iostream>

using namespace std;

int n, m;
int a[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        swap(a[x], a[y]);
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";

    return 0;
}