#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, max_val;
string ans;
map<string, int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        m[s]++;
    }
    for (auto i : m) {
        if (i.second > max_val) {
            max_val = i.second;
            ans = i.first;
        }
    }
    cout << ans << "\n";

    return 0;
}