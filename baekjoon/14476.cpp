#include <iostream>

using namespace std;

int arr[1000001];
int l[1000001];
int r[1000001];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int g = 1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    l[0] = arr[0];
    r[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++) {
        l[i] = gcd(arr[i], l[i - 1]);
        r[n - i - 1] = gcd(arr[n - i - 1], r[n - i]);
    }

    int ans = -1, k;
    for (int i = 0; i < n; i++) {
        int tmp;
        if (i == 0) tmp = r[i + 1];
        else if (i == n - 1) tmp = l[i - 1];
        else tmp = gcd(l[i - 1], r[i + 1]);
        if (arr[i] % tmp && ans < tmp) {
            ans = tmp;
            k = arr[i];
        }
    }

    if (ans == -1) cout << ans << "\n";
    else cout << ans << " " << k << "\n";

    return 0;
}