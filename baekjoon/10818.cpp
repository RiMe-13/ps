#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int mi = 2147483647, ma = -2147483647;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > ma) ma = tmp;
        if (tmp < mi) mi = tmp;
    }

    cout << mi << " " << ma << "\n";

    return 0;
}