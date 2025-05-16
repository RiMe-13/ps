#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    int res = 0;
    string num;
    bool minus = false;

    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == '-' || s[i] == '+' || i == s.length()) {
            if (minus) {
                res -= stoi(num);
                num = "";
            }
            else {
                res += stoi(num);
                num = "";
            }
        }
        else num += s[i];

        if (s[i] == '-') minus = true;
    }
    cout << res << "\n";

    return 0;
}