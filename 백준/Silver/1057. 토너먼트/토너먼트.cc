#include <iostream>

using namespace std;

int n, a, b, cnt, r = 2;
bool flag;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> b;
    a--;
    b--;
    while (r <= n) {
        cnt++;
        if (a / r == b / r) {
            flag = true;
            break;
        }
        r <<= 1;
    }
    
    if (flag) cout << cnt << "\n";
    else cout << cnt + 1 << "\n";

    return 0;
}