#include <iostream>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int j = 1, k = n;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) cout << j++ << " ";
        else cout << k-- << " ";
    }
    cout << "\n";

    return 0;
}