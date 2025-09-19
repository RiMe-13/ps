#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << 2000 << "\n";
    for (int i = 0; i < 1000; ++i)
        cout << 1 << ' ';
    for (int i = 0; i < 1000; ++i)
        cout << 1000 << ' ';
    cout << "\n";

    return 0;
}