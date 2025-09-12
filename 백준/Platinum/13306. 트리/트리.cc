#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> pi;

int n, q;
int parent[200001], v[200001];
vector<string> ans;
vector<pi> query;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    parent[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 2; i <= n; i++) cin >> v[i];
    for (int i = 0; i < n + q - 1; i++) {
        int x, a, b;
        cin >> x;
        if (x == 0) {
            cin >> a;
            query.push_back({x, {a, 0}});
        }
        else {
            cin >> a >> b;
            query.push_back({x, {a, b}});
        }
    }

    for (int i = 1; i <= n; i++) parent[i] = i;

    reverse(query.begin(), query.end());

    for (auto i : query) {
        if (i.first == 0) Union(i.second.first, v[i.second.first]);
        else {
            if (find(i.second.first) == find(i.second.second)) ans.push_back("YES");
            else ans.push_back("NO");
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto i : ans) cout << i << "\n";

    return 0;
}