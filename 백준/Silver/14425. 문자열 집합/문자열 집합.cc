#include <iostream>
#include <unordered_set>

using namespace std;

int n, m, cnt;
unordered_set<string> u;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        u.insert(s);
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (u.count(s)) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}