#include <iostream>

using namespace std;

int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) cout << s;
    cout << "\n";

    return 0;
}