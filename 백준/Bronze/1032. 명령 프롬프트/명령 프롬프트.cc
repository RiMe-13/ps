#include <iostream>
#include <string>

using namespace std;

int n;
string s[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 0; i < s[0].length(); i++) {
        char c = s[0][i];
        for (int j = 0; j < n; j++) {
            if (c != s[j][i]) {
                c = '?';
                break;
            }
        }
        cout << c;
    }
    cout << "\n";

    return 0;
}