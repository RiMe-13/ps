#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

int n, m;
int parent[1001];
double ans;
vector<pii> coord;
vector<pair<double, pii>> edge;

double dist(pii p1, pii p2) {
    double x2 = pow(p1.first - p2.first, 2);
    double y2 = pow(p1.second - p2.second, 2);

    return sqrt(x2 + y2);
}

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
    cout << fixed;
    cout.precision(2);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coord.push_back({x, y});
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a) != find(b)) Union(a, b);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            pii p1 = coord[i], p2 = coord[j];

            double d = dist(p1, p2);
            edge.push_back({d, {i + 1, j + 1}});
        }
    }
    sort(edge.begin(), edge.end());

    for (auto i : edge) {
        double dist = i.first;
        int p1 = i.second.first;
        int p2 = i.second.second;

        if (find(p1) != find(p2)) {
            Union(p1, p2);
            ans += dist;
        }
    }

    cout << ans << "\n";

    return 0;
}