#include <iostream>

using namespace std;

int a, b, c;
int h, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    m = a * 60 + b + c;
    h = (m / 60) % 24;
    m %= 60;
    cout << h << " " << m << "\n";

    return 0;
}