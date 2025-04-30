#include <iostream>

using namespace std;

int n, m;
int parent[201];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void _union(int x, int y) {
    x = find(x);
    y = find(y);

    parent[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp;
            cin >> tmp;

            if (tmp == 1) _union(i, j);
        }
    }

    int x;
    cin >> x;
    int root = find(x);
    for (int i = 1; i < m; i++) {
        cin >> x;
        if (root != find(x)) {
            cout << "NO\n";
            return 0;
        } 
    }
    cout << "YES\n";

    return 0;
}