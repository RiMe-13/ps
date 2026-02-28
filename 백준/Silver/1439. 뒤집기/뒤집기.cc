#include <iostream>
#include <string>

using namespace std;

string s;
int cnt0, cnt1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != s[i + 1]) {
            if (s[i] == '0') cnt0++;
            else cnt1++;
        }
    }
    cout << min(cnt0, cnt1) << "\n";

    return 0;
}