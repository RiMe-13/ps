#include <iostream>
#include <algorithm>

using namespace std;

int n, s;
double t;
pair<double, int> a[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t >> s;
        a[i] = {t / s, i + 1};
    }
    
    sort(a, a + n);

    for (int i = 0; i < n; i++) cout << a[i].second << " ";
    cout << "\n";

    return 0;
}