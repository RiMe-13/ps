#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;
int arr[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);
    ans = arr[0] * arr[n - 1];
    cout << ans << "\n";

    return 0;
}