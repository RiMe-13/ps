#include <iostream>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    n /= 4;
    for (int i = 0; i < n; i++) cout << "long ";
    cout << "int\n";

    return 0;
}