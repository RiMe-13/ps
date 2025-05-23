#include <iostream>
#include <algorithm>

using namespace std;

int n;
int p[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);

    int sum = 0;
    for (int i = 0; i < n; i++) sum += (n - i) * p[i];
    cout << sum << "\n";

    return 0;
}