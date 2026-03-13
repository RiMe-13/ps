#include <iostream>

using namespace std;

int n, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 5 ; i <= n; i *= 5) cnt += (n / i);
    cout << cnt << "\n";

    return 0;
}