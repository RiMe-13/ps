#include <iostream>
#include <string>
#include <regex>

using namespace std;

int t;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> s;
        regex pattern("(100+1+|01)+");
        if (regex_match(s, pattern)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}