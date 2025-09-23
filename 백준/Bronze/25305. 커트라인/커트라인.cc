#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int a[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a + n, greater<>());

    cout << a[k - 1] << "\n";

    return 0;
}