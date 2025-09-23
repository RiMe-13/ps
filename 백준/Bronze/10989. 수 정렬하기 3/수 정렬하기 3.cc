#include <iostream>

using namespace std;

int n, cnt[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }

    for (int i = 0; i <= 10000; i++) {
        if (cnt[i]) {
            while (cnt[i]--) cout << i << "\n";
        }
    }

    return 0;
}