#include <iostream>

using namespace std;

int h, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> m;
    if (m < 45) {
        m += 15;
        if (--h < 0) h = 23;
    }
    else m -= 45;

    cout << h << " " << m << "\n";

    return 0;
}