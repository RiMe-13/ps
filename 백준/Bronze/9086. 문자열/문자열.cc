#include <iostream>
#include <string>

using namespace std;

int t;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> s;
        cout << s[0] << s[s.length() - 1] << "\n";
    }

    return 0;
}