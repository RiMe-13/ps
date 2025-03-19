#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> adj[1001];
vector<int> ans;
int indegree[1001];
queue<int> q;

void bfs() {
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        ans.push_back(cur);
        q.pop();

        for (int v : adj[cur]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int num;
        vector<int> v;
        cin >> num;
        int a;
        cin >> a;
        for (int j = 1; j < num; j++) {
            int b;
            cin >> b;
            adj[a].push_back(b);
            indegree[b]++;
            a = b;
        }
    }

    bfs();

    if (ans.size() == n) {
        for (int i = 0; i < n; i++) cout << ans[i] << "\n";
    }
    else cout << "0\n"; 

    return 0;
}