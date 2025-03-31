#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> pi;
vector<int> res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string t, p;

    getline(cin, t);
    getline(cin, p);

    int n = t.size();
    int m = p.size();
    int j = 0;

    pi.resize(m, 0);
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j]) j = pi[j - 1];
        if (p[i] == p[j]) pi[i] = ++j;
    }

    j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && t[i] != p[j]) j = pi[j - 1];
        if (t[i] == p[j]) {
            if (j == m - 1) {
                res.push_back(i - m + 1);
                j = pi[j];
            }
            else j++;
        }
    }

    cout << res.size() << "\n";
    for (int i : res) cout << i + 1 << "\n";

    return 0;
}