#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int i;
    cin >> s;
    cin >> i;
    cout << s[i - 1] << "\n";

    return 0;
}