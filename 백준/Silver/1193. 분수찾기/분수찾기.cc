#include <iostream>

using namespace std;

int x, line = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x;
    while (x > line) x -= line++;

    if (line % 2) cout << line - x + 1 << "/" << x << "\n";
    else cout << x << "/" << line - x + 1 << "\n";

    return 0;
}