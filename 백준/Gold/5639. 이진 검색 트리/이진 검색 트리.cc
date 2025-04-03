#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> tree;

void postorder(int s, int e) {
    if (s >= e) return;
    if (s == e - 1) {
        cout << tree[s] << "\n";
        return;
    }

    int i = s + 1;
    while (i < e) {
        if (tree[s] < tree[i]) break;
        i++;
    }

    postorder(s + 1, i);
    postorder(i, e);
    cout << tree[s] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n) {
        tree.push_back(n);
    }

    postorder(0, tree.size());

    return 0;
}