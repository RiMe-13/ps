#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;

bool cmp(string s1, string s2) {
    if (s1.length() == s2.length()) return s1 < s2;
    else return s1.length() < s2.length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) {
        if (i != 0 && v[i] == v[i - 1]) continue;
        cout << v[i] << "\n";
    }

    return 0;
}