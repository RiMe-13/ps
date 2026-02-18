#include <iostream>

using namespace std;

int min_val = 1e9, cnt;
int a[5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; i++) {
        cin >> a[i];
        min_val = min(min_val, a[i]);
    }

    int t = min_val - 1;
    while (cnt < 3) {
        t++;
        cnt = 0;
        for (int i = 0; i < 5; i++) {
            if (t % a[i] == 0) cnt++;
        }
    }

    cout << t << "\n";

    return 0;
}