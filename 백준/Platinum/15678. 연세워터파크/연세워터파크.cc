#include <iostream>

using namespace std;

typedef long long ll;

int n, d, first_idx = 1;
ll k[100001], tree[400001];

void update(int idx, ll val) {
    int node = first_idx + idx;
    tree[node] = val;
    while (node > 0) {
        node /= 2;
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}

ll get_max(int a, int b) {
    int left = first_idx + a, right = first_idx + b;
    ll res = 0LL;

    while (left <= right) {
        if (left % 2 == 1) res = max(res, tree[left++]);
        if (right % 2 == 0) res = max(res, tree[right--]);
        left /= 2;
        right /= 2;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> k[i];

    while (first_idx < n) first_idx *= 2;
	first_idx--;

    ll ans = k[1];
    update(1, k[1]);
    for (int i = 2; i <= n; i++) {
        ll tmp = max(0LL, get_max(max(1LL, (ll)i - d), i - 1));
        ans = max(ans, k[i] + tmp);
        update(i, k[i] + tmp);
    }

    cout << ans << "\n";

    return 0;
}