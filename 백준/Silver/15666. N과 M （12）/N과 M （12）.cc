#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[9], ans[9];

void dfs(int x, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }

    int tmp = -1;
    for (int i = x; i < n; i++) {
        if (tmp != a[i]) {
            tmp = a[i];
            ans[cnt] = a[i];
            dfs(i, cnt + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    dfs(0, 0);

    return 0;
}