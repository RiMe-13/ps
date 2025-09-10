#include <iostream>

using namespace std;

int n, q, sum;
int parent[600001], s[600001];

int rev(int x) {
    if (x < n) return x + n;
    return x - n;
}

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;

    if (find(rev(y)) == y) sum -= s[y];
    if (find(rev(x)) == x) sum -= s[x];

    parent[y] = x;
    s[x] += s[y];
    if (find(rev(x)) == x) sum += s[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 0; i <= 2 * n; i++) {
        parent[i] = i;
        s[i] = 1;
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, rev(b));
        Union(rev(a), b);
        cout << sum / 2 << "\n";
    }

    return 0;
}