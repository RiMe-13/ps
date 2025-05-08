#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int t, f;
unordered_map<string, string> parent;
unordered_map<string, int> cnt;

string find(string a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void Union(string a, string b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    parent[b] = a;
    cnt[a] += cnt[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        parent.clear();
        cnt.clear();

        cin >> f;
        for (int i = 0; i < f; i++) {
            string a, b;
            cin >> a >> b;

            if (parent.count(a) == 0) {
                parent[a] = a;
                cnt[a] = 1;
            }
            if (parent.count(b) == 0) {
                parent[b] = b;
                cnt[b] = 1;
            }
            Union(a, b);
            cout << cnt[find(a)] << "\n";
        }
    }

    return 0;
}