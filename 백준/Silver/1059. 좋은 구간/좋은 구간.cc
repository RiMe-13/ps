#include <iostream>
#include <algorithm>

using namespace std;

int l, n;
int a[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> l;
    for (int i = 0; i < l; i++) cin >> a[i];
    cin >> n;

    sort(a, a + l + 1);

    int s, e;
    bool flag = true;
    for (int i = 1; i <= l; i++) {
        if (n == a[i]) {
            flag = false;
            break;
        }
        else if (n < a[i]) {
            s = a[i - 1] + 1;
            e = a[i] - 1;
            break;
        }
    }

    if (flag) cout << (n - s) * (e - n + 1) + (e - n) << "\n";
    else cout << "0\n";

    return 0;
}