#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e;
int parent[10001];
vector<pair<int, pair<int, int>>> edge;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void _union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }
    sort(edge.begin(), edge.end());
    for (int i = 1; i <= v; i++) parent[i] = i;

    int ans = 0;
    for (auto i : edge) {
        if (find(i.second.first) != find(i.second.second)) {
            _union(i.second.first, i.second.second);
            ans += i.first;
        }
    }
    cout << ans << "\n";

    return 0;
}