#include <iostream>

using namespace std;

int n, m, k;
const int MOD = 1000000007;
int first_idx = 1;
long long tree[2100000];

void update(int idx, int val) {
    int node = first_idx + idx;
    tree[node] = val;
    node /= 2;
    while (node > 0) {
        tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
        node /= 2;
    }
}

long long get_val(int a, int b) {
    int left = first_idx + a, right = first_idx + b;
    long long res = 1;

    while (left <= right) {
        if (left % 2 == 1) res = (res * tree[left++]) % MOD;
        if (right % 2 == 0) res = (res * tree[right--]) % MOD;
        left /= 2;
        right /= 2;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    while (first_idx < n) first_idx *= 2;
    first_idx--;

    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        update(i, v);
    }

    for (int i = 0; i < m + k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) update(b, c);
        else cout << get_val(b, c) << "\n";
    }

    return 0;
}