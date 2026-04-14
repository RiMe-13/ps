#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans;
vector<string> str;
bool check[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        str.push_back(s);
        check[i] = true;
    }

    sort(str.begin(), str.end());

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[j].substr(0, str[i].size()) == str[i]) {
                check[i] = false;
                break;
            }
        }
    }

    for (bool i : check) {
        if (i) ans++;
    }
    cout << ans << "\n";

    return 0;
}