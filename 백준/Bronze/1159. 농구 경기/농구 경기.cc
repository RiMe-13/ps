#include <iostream>
#include <string>

using namespace std;

int n;
bool flag;
int cnt[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cnt[s[0] - 'a']++;
        if (cnt[s[0] - 'a'] >= 5) flag = true;
    }

    if (flag) {
        for (int i = 0; i < 26; i++) {
            if (cnt[i] >= 5) cout << (char) (i + 'a');
        }
        cout << "\n";
    }
    else cout << "PREDAJA\n";

    return 0;
}