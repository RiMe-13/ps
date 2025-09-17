#include <iostream>

using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    if (n == k) cout << "Impossible\n";
    else {
        cout << n - k << " ";
        for (int i = 1; i < n - k; i++) cout << i << " ";
        for (int i = n - k + 1; i <= n; i++) cout << i << " ";
        cout << "\n";
    }
    
    return 0;
}