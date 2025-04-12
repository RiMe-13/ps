#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Node {
    int left = 0, right = 0, idx = 0;
    int cnt = 0;
    long long sum = 0;
};

int q, cnt;
string names[100001];
int value[100001];
vector<Node> tree;
map<string, int> m;
set<int> used_val;

void update(int node, int left, int right, int pos, int idx, int cnt, int sum) {
    if (right < pos || left > pos) return;

    if (left == right) {
        tree[node].idx = idx;
        tree[node].cnt = cnt;
        tree[node].sum = sum;
        return;
    }

    int mid = (left + right) / 2;
    if (pos <= mid) {
        if (!tree[node].left) {
            tree[node].left = tree.size();
            Node n;
            tree.push_back(n);
        }
        update(tree[node].left, left, mid, pos, idx, cnt, sum);
    }
    else {
        if (!tree[node].right) {
            tree[node].right = tree.size();
            Node n;
            tree.push_back(n);
        }
        update(tree[node].right, mid + 1, right, pos, idx, cnt, sum);
    }

    tree[node].cnt = tree[tree[node].left].cnt + tree[tree[node].right].cnt;
    tree[node].sum = tree[tree[node].left].sum + tree[tree[node].right].sum;
}

long long get_sum(int node, int left, int right, int q_left, int q_right) {
    if (q_right < left || right < q_left) return 0;

    if (q_left <= left && right <= q_right) return tree[node].sum;

    int mid = (left + right) / 2;
    long long res = 0;
    if (tree[node].left) res += get_sum(tree[node].left, left, mid, q_left, q_right);
    if (tree[node].right) res += get_sum(tree[node].right, mid + 1, right, q_left, q_right);

    return res;
}

int get_rank(int node, int left, int right, int k) {
    if (left == right) return tree[node].idx;

    int mid = (left + right) / 2;
    if (tree[node].left) {
        if (tree[tree[node].left].cnt >= k) return get_rank(tree[node].left, left, mid, k);
        return get_rank(tree[node].right, mid + 1, right, k - tree[tree[node].left].cnt);
    }
    return get_rank(tree[node].right, mid + 1, right, k);
}

void init() {
    cnt = 0;
    tree.clear();
    m.clear();
    used_val.clear();

    Node root, dummy;
    tree.push_back(root);
    tree.push_back(dummy);
}

int insert(string name, int val) {
    if (m.find(name) != m.end() || used_val.find(val) != used_val.end()) return 0;

    m[name] = ++cnt;
    names[cnt] = name;
    used_val.insert(val);
    value[cnt] = val;

    update(1, 1, 1e9, val, cnt, 1, val);
    return 1;
}

int del(string name) {
    if (m.find(name) == m.end()) return 0;

    int idx = m[name];
    m.erase(name);
    used_val.erase(value[idx]);

    update(1, 1, 1e9, value[idx], idx, 0, 0);
    return value[idx];
}

string Rank(int k) {
    if (tree[1].cnt < k) return "None";

    int idx = get_rank(1, 1, 1e9, k);
    return names[idx];
}

long long sum(int k) {
    long long res = get_sum(1, 1, 1e9, 1, k);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> q;
    for (int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "init") {
            init();
        }
        else if (cmd == "insert") {
            string name;
            int val;
            cin >> name >> val;
            cout << insert(name, val) << "\n";
        }
        else if (cmd == "delete") {
            string name;
            cin >> name;
            cout << del(name) << "\n";
        }
        else if (cmd == "rank") {
            int k;
            cin >> k;
            cout << Rank(k) << "\n";
        }
        else if (cmd == "sum") {
            int k;
            cin >> k;
            cout << sum(k) << "\n";
        }
    }

    return 0;
}