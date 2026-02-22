#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
int odd;
char odd_c;
int cnt[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    for (char c : s) {
        cnt[c - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2) {
            odd++;
            odd_c = i + 'A';
        }
    }

    if (odd > 1) cout << "I'm Sorry Hansoo\n";
    else {
        string first = "";
        for (int i = 0; i < 26; i++) {
            first += string(cnt[i] / 2, i + 'A');
        }
        string second = first;
        reverse(second.begin(), second.end());
        if (odd == 1) first += odd_c;

        cout << first + second << "\n";
    }

    return 0;
}