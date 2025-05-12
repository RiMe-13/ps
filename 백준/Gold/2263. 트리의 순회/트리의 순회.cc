#include <iostream>

using namespace std;

int n;
int idx[100001], inorder[100001], postorder[100001];

void find_order(int in_s, int in_e, int post_s, int post_e) {
    if (in_s > in_e || post_s > post_e) return;

    int root_idx = idx[postorder[post_e]];
    int left = root_idx - in_s;
    int right = in_e - root_idx;
    cout << inorder[root_idx] << " ";

    find_order(in_s, root_idx - 1, post_s, post_s + left - 1);
    find_order(root_idx + 1, in_e, post_s + left, post_e - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }
    for (int i = 1; i <= n; i++) cin >> postorder[i];

    find_order(1, n, 1, n);
    cout << "\n";

    return 0;
}