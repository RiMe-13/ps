#include <iostream>
#include <vector>

using namespace std;

int n;
int parent[100001];
bool visited[100001];
vector<int> adj[100001];

void dfs(int x) {
    visited[x] = true;
    for (int i : adj[x]) {
        if (!visited[i]) {
            parent[i] = x;
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    
    for (int i = 2; i <= n; i++) cout << parent[i] << "\n";

    return 0;
}