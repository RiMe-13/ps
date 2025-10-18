#include <iostream>

using namespace std;

int n, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i * i <= n; i++) cnt++;
    cout << cnt << "\n";

    return 0;
}