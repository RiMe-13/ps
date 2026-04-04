#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> adj[51];

int dfs(int cur) {
    vector<int> v;
    int res = 0;
    int w = adj[cur].size() - 1;

    for (int nxt : adj[cur]) v.push_back(dfs(nxt));

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) res = max(res, v[i] + w--);

    return res + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == -1) continue;

        adj[tmp].push_back(i);
    }
    int ans = dfs(0);

    cout << ans - 1 << "\n";

    return 0;
}