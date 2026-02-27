#include <iostream>

using namespace std;

int n;
int a[11], ans[11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        int j = 0;
        while (a[i] != 0) {
            if (ans[j] == 0) a[i]--;
            j++;
        }
        while (ans[j] != 0) j++;
        ans[j] = i + 1;
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";

    return 0;
}