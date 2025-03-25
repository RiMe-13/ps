#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int first_idx = 1;
int n, m;
int min_tree[270000], max_tree[270000];

void update(int i, int n) {
    int node = first_idx + i;
    min_tree[node] = max_tree[node] = n;
    node /= 2;
    while (node > 0) {
        min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
        max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
        node /= 2;
    }
}

pii get_val(int a, int b) {
    int left = first_idx + a;
    int right = first_idx + b;
    int max_val = 0, min_val = 2147483647;

    while (left <= right) {
        if (left % 2 == 1) {
            max_val = max(max_val, max_tree[left]);
            min_val = min(min_val, min_tree[left]);
            left++;
        }
        if (right % 2 == 0) {
            max_val = max(max_val, max_tree[right]);
            min_val = min(min_val, min_tree[right]);
            right--;
        }
        left /= 2;
        right /= 2;
    }

    return {min_val, max_val};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 270000; i++) min_tree[i] = 2147483647;

    cin >> n >> m;
    while (first_idx < n) first_idx *= 2;
    first_idx--;

    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        update(i, tmp);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        pii res = get_val(a, b);
        cout << res.first << " " << res.second << "\n";
    }

    return 0;
}