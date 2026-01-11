#include <iostream>
#include <string>

using namespace std;

string s;
bool palindrome = true;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    int l = s.length();
    for (int i = 0; i < l / 2; i++) {
        if (s[i] != s[l - 1 - i]) {
            palindrome = false;
            break;
        }
    }
    if (palindrome) cout << "1\n";
    else cout << "0\n";

    return 0;
}