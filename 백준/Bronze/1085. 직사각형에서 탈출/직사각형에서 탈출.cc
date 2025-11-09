#include <iostream>

using namespace std;

int x, y, w, h;
int tmp1, tmp2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> y >> w >> h;
    tmp1 = min(x, y);
    tmp2 = min(w - x, h - y);
    cout << min(tmp1, tmp2) << "\n";

    return 0;
}