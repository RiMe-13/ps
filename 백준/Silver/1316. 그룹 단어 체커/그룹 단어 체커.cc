#include <iostream>
#include <string>

using namespace std;

int n, cnt;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;

        bool alpha[26] = { false, };
        alpha[s[0] - 'a'] = true;

        for (int j = 1; j < s.length(); j++) {
            if (s[j] == s[j - 1]) continue;
            else if (alpha[s[j] - 'a']) {
                cnt++;
                break;
            }
            else alpha[s[j] - 'a'] = true;
        }
    }
    cout << n - cnt << "\n";

    return 0;
}