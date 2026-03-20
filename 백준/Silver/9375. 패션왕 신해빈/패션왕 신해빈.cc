#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int t, n;
string s1, s2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        unordered_map<string, int> um;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s1 >> s2;
            um[s2]++;
        }

        int ans = 1;
        for (auto i : um) ans *= (i.second + 1);
        ans--;
        cout << ans << "\n";
    }

    return 0;
}