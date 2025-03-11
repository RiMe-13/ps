#include <iostream>
#include <cstring>

using namespace std;

int arr[41];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        memset(arr, 0, sizeof(arr));
        cin >> n;
        if (n == 0) cout << "1 0\n";
        else if (n == 1) cout << "0 1\n";
        else {
            arr[0] = 1, arr[1] = 1;
            for (int i = 2; i <= n; i++) arr[i] = arr[i - 1] + arr[i - 2];
            cout << arr[n - 2] << " " << arr[n - 1] << "\n";
        }
    }

    return 0;
}