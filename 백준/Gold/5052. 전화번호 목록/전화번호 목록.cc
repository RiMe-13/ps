#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int t, n;
vector<string> v;
unordered_set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> n;
        v.clear();
        s.clear();
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            v.push_back(tmp);
        }

        sort(v.begin(), v.end());
        bool flag = false;
        for (int i = 0; i < n; i++) {
            string str = "";
            for (int j = 0; j < v[i].length() - 1; j++) {
                str += v[i][j];
                if (s.find(str) != s.end()) {
                    flag = true;
                    cout << "NO\n";
                    break;
                }
            }
            if (flag) break;
            s.insert(v[i]);
        }

        if (!flag) cout << "YES\n";
    }

    return 0;
}