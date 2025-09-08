#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
int parent[1001];
vector<int> f[1001], e[1001];
set<int> cnt;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x), y = find(y);
    parent[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
        char cmd;
        int p, q;
        cin >> cmd >> p >> q;

        if (cmd == 'E') {
            e[p].push_back(q);
            e[q].push_back(p);
        }
        else if (cmd == 'F') {
            f[p].push_back(q);
            f[q].push_back(p);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j : f[i]) Union(i, j);
        for (int j : e[i]) {
            for (int k : e[j]) Union(i, k);
        }
    }

    for (int i = 1; i <= n; i++) cnt.insert(find(i));

    cout << cnt.size() << "\n";

    return 0;
}