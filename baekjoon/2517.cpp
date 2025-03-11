#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;
int first_idx = 1;
vector<pii> a;
int tree[1050001];

bool comp(const pii &p1, const pii &p2) {
    return p1.second < p2.second;
}

int sum(int a, int b) {
    int left = first_idx + a, right = first_idx + b;
    int res = 0;

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
    while (node > 0) {
        node /= 2;
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back({tmp, i});
    }

    sort(a.begin(), a.end());
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        a[i].first = cnt++;
    }
    sort(a.begin(), a.end(), comp);

    while (first_idx < n) first_idx *= 2;
	first_idx--;

    for (int i = 0; i < n; i++) {
        int result = sum(1, a[i].first);
        update(a[i].first, 1);
        cout << (i + 1) - result << "\n";
    }

    return 0;
}