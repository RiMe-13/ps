#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
bool flag;
string s[1001];

bool cmp(string a, string b) {
    if (a == b) return false;

    string ab = a + b, ba = b + a;
    if (ab > ba) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i] != "0") flag = true;
    }

    if (!flag) cout << "0\n";
    else {
        sort(s, s + n, cmp);
        for (int i = 0; i < n; i++) cout << s[i];
        cout << "\n";
    }

    return 0;
}