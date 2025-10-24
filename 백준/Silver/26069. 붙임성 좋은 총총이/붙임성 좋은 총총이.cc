#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int n;
unordered_set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        if (s1 == "ChongChong") s.insert(s2);
        else if (s2 == "ChongChong") s.insert(s1);

        if (s.count(s1)) s.insert(s2);
        if (s.count(s2)) s.insert(s1);
    }

    cout << s.size() << "\n";

    return 0;
}