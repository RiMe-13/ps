#include <iostream>
#include <string>

using namespace std;

string s, ans;
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'X') cnt++;
        else {
            ans += '.';
            if (cnt % 2) break;
            else cnt = 0;
        }

        if (cnt == 2 && s[i + 1] != 'X') {
            ans += "BB";
            cnt = 0;
        }
        if (cnt == 4) {
            ans += "AAAA";
            cnt = 0;
        }
    }

    if (cnt % 2) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}