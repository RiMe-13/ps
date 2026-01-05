#include <iostream>
#include <string>

using namespace std;

string s;
int cnt = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    getline(cin, s);
    if (s.length() == 1 && s[0] == ' ') cout << "0\n";
    else {
        for (int i = 1; i < s.length() - 1; i++) {
            if (s[i] == ' ') cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}