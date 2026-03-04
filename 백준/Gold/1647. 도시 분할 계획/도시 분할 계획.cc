#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m, ans;
int parent[100001];
vector<pair<int, pii>> edge;
vector<int> v;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;
    parent[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }

    sort(edge.begin(), edge.end());
    for (int i = 1; i <= n; i++) parent[i] = i;

    for (auto i : edge) {
        if (find(i.second.first) != find(i.second.second)) {
            Union(i.second.first, i.second.second);
            v.push_back(i.first);
        }
    }

    for (int i = 0; i < v.size() - 1; i++) ans += v[i];
    cout << ans << "\n";

    return 0;
}