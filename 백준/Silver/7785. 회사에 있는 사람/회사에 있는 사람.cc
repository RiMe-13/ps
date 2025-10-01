#include <iostream>
#include <set>

using namespace std;

int n;
set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s2 == "enter") s.insert(s1);
        else s.erase(s1);
    }

    for (auto i = s.rbegin(); i != s.rend(); i++) {
        cout << *i << "\n";
    }

    return 0;
}