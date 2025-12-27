#include <iostream>

using namespace std;

int a[10001];
int n, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < x) cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}