#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans;
int a[51], b[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + n, greater<>());

    for (int i = 0; i < n; i++) ans += a[i] * b[i];
    cout << ans << "\n";

    return 0;
}