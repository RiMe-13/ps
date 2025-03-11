#include <iostream>
#include <set>

using namespace std;

set<string> s, res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string name;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> name;
        s.insert(name);
    }
    for (int i = 0; i < m; i++) {
        cin >> name;
        if (s.find(name) != s.end()) res.insert(name);
    }

    cout << res.size() << "\n";
    for (string i : res) cout << i << "\n";

    return 0;
}