#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
vector<string> v;
unordered_map<string, int> um;

bool cmp(string a, string b) {
    if (a.length() == b.length() && um[a] == um[b]) return a < b;
    else if (um[a] == um[b]) return a.length() > b.length();
    return um[a] > um[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str.length() < m) continue;
        if (um.find(str) == um.end()) v.push_back(str);
        um[str]++;
    }

    sort(v.begin(), v.end(), cmp);

    for (string i : v) cout << i << "\n";

    return 0;
}