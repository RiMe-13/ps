#include <iostream>

using namespace std;

int a, b, v, d = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> v;
    d += (v - a) / (a - b);
    if ((v - a) % (a - b)) d++;

    if (a >= v) cout << "1\n";
    else cout << d << "\n";

    return 0;
}