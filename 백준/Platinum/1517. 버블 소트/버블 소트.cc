#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, first_idx = 1;
long long ans;
int tree[1050000];
vector<pii> arr;

long long sum(int a, int b) {
    int left = first_idx + a, right = first_idx + b;
    long long res = 0;

    while (left <= right) {
        if (left % 2 == 1) res += tree[left++];
        if (right % 2 == 0) res += tree[right--];

        left /= 2;
        right /= 2;
    }

    return res;
}

void update(int idx, int val) {
    int node = first_idx + idx;
    tree[node] = val;
    node /= 2;

    while (node > 0) {
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
        node /= 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (first_idx < n) first_idx *= 2;
    first_idx--;

    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back({tmp, i});
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        ans += sum(arr[i].second, n);
        update(arr[i].second, 1);
    }

    cout << ans << "\n";

    return 0;
}