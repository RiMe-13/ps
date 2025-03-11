#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[9];
int ans[9];
bool visited[9];

void dfs(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    int prev = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && a[i] != prev) {
            visited[i] = true;
            ans[cnt] = a[i];
            prev = ans[cnt];
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    dfs(0);

    return 0;
}