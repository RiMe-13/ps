#include <iostream>

using namespace std;

int n, v, cnt;
int a[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> v;
    for (int i = 0; i < n; i++) {
        if (a[i] == v) cnt++;
    }
    cout << cnt << "\n";

    return 0;
}