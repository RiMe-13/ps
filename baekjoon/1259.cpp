#include <iostream>

using namespace std;

bool is_palindrome(string s) {
    for (int i = 0; i <= s.length() / 2; i++) {
        if (s[i] != s[s.length() - 1 - i]) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (true) {
        cin >> s;
        if (s == "0") break;

        if (is_palindrome(s)) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}