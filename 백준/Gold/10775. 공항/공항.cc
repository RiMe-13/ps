#include <iostream>

using namespace std;

int g, p, ans;
int parent[100001];

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    a = find(a), b = find(b);

    if (a > b) swap(a, b);

    parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> g >> p;
    for (int i = 0; i <= g; i++) parent[i] = i;
    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;

        x = find(x);
        if (x == 0) break;
        Union(x, x - 1);
        ans++;
    }
    cout << ans << "\n";

    return 0;
}