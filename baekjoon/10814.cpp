#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<pair<int, int>, string>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        v.push_back({{age, i}, name});
    }
    sort(v.begin(), v.end());
    for (pair<pair<int, int>, string> i : v) cout << i.first.first << " " << i.second << "\n";

    return 0;
}