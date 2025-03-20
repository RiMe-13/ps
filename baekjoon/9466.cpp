#include <iostream>
#include <cstring>

using namespace std;

int n;
int cnt;
int map[100001];
bool visited[100001];
bool isCycle[100001];

void dfs(int n) {
    visited[n] = true;
    int next = map[n];

    if (!visited[next]) dfs(next);
    else if (!isCycle[next]) {
        for (int i = next; i != n; i = map[i]) cnt++;
        cnt++;
    }
    isCycle[n] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cnt = 0;
        memset(visited, false, sizeof(visited));
        memset(isCycle, false, sizeof(isCycle));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> map[i];
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) dfs(i);
        }
        cout << n - cnt << "\n";
    }

    return 0;
}