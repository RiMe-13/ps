#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n, m;
int in[501];
bool visited[501];
vector<int> adj[501];
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        memset(in, 0, sizeof(in));
        memset(visited, false, sizeof(visited));
        for (int i = 0; i <= 501; i++) adj[i].clear();
        q = {};

        cin >> n;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            visited[v] = true;
            for (int j = 1; j <= n; j++) {
                if (!visited[j]) {
                    adj[v].push_back(j);
                    in[j]++;
                }
            }
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            auto it = find(adj[b].begin(), adj[b].end(), a);
            if (it != adj[b].end()) {
                adj[b].erase(it);
                in[a]--;
                adj[a].push_back(b);
                in[b]++;
            }
            else {
                it = find(adj[a].begin(), adj[a].end(), b);
                adj[a].erase(it);
                in[b]--;
                adj[b].push_back(a);
                in[a]++;
            }
        }

        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) q.push(i);
        }

        bool flag = false;
        while (!q.empty()) {
            if (q.size() > 1) {
                flag = true;
                break;
            }

            int cur = q.front();
            q.pop();
            ans.push_back(cur);

            for (int v : adj[cur]) {
                in[v]--;
                if (in[v] == 0) q.push(v);
            }
        }

        if (flag) cout << "?\n";
        else if (ans.size() != n) cout << "IMPOSSIBLE\n";
        else {
            for (int i : ans) cout << i << " ";
            cout << "\n";
        }
    }

    return 0;
}