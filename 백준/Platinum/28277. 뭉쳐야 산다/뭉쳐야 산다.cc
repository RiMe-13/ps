#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    vector<set<int>> v(n + 1);
    for (int i = 1; i <= n; i++) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) {
            int tmp;
            cin >> tmp;
            v[i].insert(tmp);
        }
    }
    for (int i = 0; i < q; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int a, b;
            cin >> a >> b;
            if (v[a].size() < v[b].size()) swap(v[a], v[b]);

            for (auto& x : v[b]) v[a].insert(x);
            v[b].clear();
        }
        else if (cmd == 2) {
            int a;
            cin >> a;
            cout << v[a].size() << "\n";
        }
    }

    return 0;
}