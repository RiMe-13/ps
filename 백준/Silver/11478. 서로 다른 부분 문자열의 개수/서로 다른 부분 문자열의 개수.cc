#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < str.length(); j++) {
            s.insert(str.substr(i, j));
        }
    }

    cout << s.size() << "\n";

    return 0;
}