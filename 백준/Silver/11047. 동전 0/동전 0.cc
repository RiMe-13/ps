#include <iostream>

using namespace std;

int n, k;
int val[11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> val[i];

    int cnt = 0;
    for (int i = n; i > 0; i--) {
        if (k / val[i]) {
            cnt += k / val[i];
            k %= val[i];
        }
    }
    cout << cnt << "\n";

    return 0;
}