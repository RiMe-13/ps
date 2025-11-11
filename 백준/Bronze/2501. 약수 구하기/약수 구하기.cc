#include <iostream>

using namespace std;

int n, k, cnt;
int d[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) d[cnt++] = i;
    }

    if (cnt >= k) cout << d[k - 1] << "\n";
    else cout << "0\n";

    return 0;
}