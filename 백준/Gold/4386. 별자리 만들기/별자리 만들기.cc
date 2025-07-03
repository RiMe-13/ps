#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;

int n;
int parent[101];
double ans;
vector<pdd> coord;
vector<pair<double, pii>> edge;

double dist(pdd p1, pdd p2) {
    double x2 = (p1.first - p2.first) * (p1.first - p2.first);
    double y2 = (p1.second - p2.second) * (p1.second - p2.second);

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

    cin >> n;
    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        coord.push_back({a, b});
    }

    for (int i = 0; i < coord.size(); i++) {
        pdd p1 = coord[i];

        for (int j = i + 1; j < coord.size(); j++) {
            pdd p2 = coord[j];

            double d = dist(p1, p2);
            edge.push_back({d, {i, j}});
        }
    }

    for (int i = 0; i < n; i++) parent[i] = i;
    sort(edge.begin(), edge.end());
    for (auto i : edge) {
        double cost = i.first;
        int p1 = i.second.first;
        int p2 = i.second.second;

        if (find(p1) != find(p2)) {
            Union(p1, p2);
            ans += cost;
        }
    }

    cout << ans << "\n";

    return 0;
}