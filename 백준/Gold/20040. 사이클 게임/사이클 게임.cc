#include <iostream>

using namespace std;

int n, m;
int parent[500001];

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    a = find(parent[a]);
    b = find(parent[b]);

    parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) parent[i] = i;

    bool flag = false;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b) && !flag) {
            cout << i + 1 << "\n";
            flag = true;
        }
        Union(a, b);
    }
    if (!flag) cout << "0\n";

    return 0;
}