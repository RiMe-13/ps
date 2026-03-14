#include <iostream>
#include <string>

using namespace std;

int t;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int sum = 0, streak = 0;
        cin >> s;
        if (s[0] == 'O') {
            sum++;
            streak = 1;
        }

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == 'O') sum += (++streak);
            else streak = 0;
        }

        cout << sum << "\n";
    }

    return 0;
}