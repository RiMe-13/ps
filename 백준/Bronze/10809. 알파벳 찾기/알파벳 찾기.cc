#include <iostream>
#include <string>

using namespace std;

string s;
int idx[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    for (int i = 0; i < 26; i++) idx[i] = -1;
    for (int i = 0; i < s.length(); i++) {
        if (idx[s[i] - 'a'] == -1) idx[s[i] - 'a'] = i;
    }
    for (int i = 0; i < 26; i++) cout << idx[i] << " ";
    cout << "\n";

    return 0;
}