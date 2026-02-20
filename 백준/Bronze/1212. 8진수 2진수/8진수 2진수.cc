#include <iostream>
#include <string>

using namespace std;

string s;
string a[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        int tmp = s[i] - '0';
        if (i == 0) cout << stoi(a[tmp]);
        else cout << a[tmp];
    }
    cout << "\n";

    return 0;
}