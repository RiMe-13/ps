#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int in[32001];
vector<int> adj[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) pq.push(i);
    }

    for (int i = 1; i <= n; i++) {
        int x = pq.top();
        pq.pop();
        cout << x << " ";

        for (int v : adj[x]) {
            in[v]--;
            if (in[v] == 0) pq.push(v);
        }
    }
    cout << "\n";

    return 0;
}