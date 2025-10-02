#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<string, int> book;
vector<string> name;
vector<string> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        name.push_back(tmp);
        book.insert({tmp, i});
    }
    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        if (tmp[0] >= 'A' && tmp[0] <= 'Z') ans.push_back(to_string(book[tmp]));
        else ans.push_back(name[stoi(tmp) - 1]);
    }

    for (string i : ans) cout << i << "\n";

    return 0;
}