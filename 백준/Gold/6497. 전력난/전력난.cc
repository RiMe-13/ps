#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int m, n, total, res;
int parent[200001];
vector<pair<int, pii>> edge;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    
    parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        edge.clear();
        for (int i = 0; i < 200001; i++) parent[i] = i;
        total = res = 0;

        cin >> m >> n;
        if (m == 0 && n == 0) break;

        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            edge.push_back({z, {x, y}});
            total += z;
        }

        sort(edge.begin(), edge.end());
        for (auto i : edge) {
            int len = i.first;
            int p1 = i.second.first;
            int p2 = i.second.second;

            if (find(p1) != find(p2)) {
                Union(p1, p2);
                res += len;
            }
        }

        cout << total - res << "\n";
    }

    return 0;
}