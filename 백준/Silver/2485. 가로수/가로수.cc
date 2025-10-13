#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int n, g, cnt;
int tree[100001], dist[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> tree[i];

    sort(tree, tree + n);

    for (int i = 0; i < n - 1; i++) dist[i] = tree[i + 1] - tree[i];

    g = dist[0];
    for (int i = 1; i < n - 1; i++) g = gcd(g, dist[i]);

    for (int i = 0; i < n - 1; i++) cnt += (dist[i] / g) - 1;

    cout << cnt << "\n";

    return 0;
}