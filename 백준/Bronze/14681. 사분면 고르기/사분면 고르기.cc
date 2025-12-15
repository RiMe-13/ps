#include <iostream>

using namespace std;

int x, y, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> y;
    if (y > 0) {
        if (x > 0) n = 1;
        else n = 2;
    }
    else {
        if (x < 0) n = 3;
        else n = 4;
    }
    cout << n << "\n";

    return 0;
}