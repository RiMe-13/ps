#include <iostream>

using namespace std;

int y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> y;
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) cout << "1\n";
    else cout << "0\n";

    return 0;
}