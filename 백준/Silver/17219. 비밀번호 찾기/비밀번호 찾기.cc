#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<string, string> um;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string site, pw;
        cin >> site >> pw;
        um[site] = pw;
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        cout << um[s] << "\n";
    }

    return 0;
}