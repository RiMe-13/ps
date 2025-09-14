#include <iostream>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    if (n % 2 == 1) {
        int mid = (n + 1) / 2;
        cout << mid << " ";
        for (int i = n; i > mid; i--) cout << i << " " << i - mid << " ";
    }
    else {
        int mid = n / 2;
        for (int i = n; i > mid; i--) cout << i - mid << " " << i << " ";
    }
    cout << "\n";

    return 0;
}