#include <iostream>
#include <queue>

using namespace std;

int n, cnt[10], types, ans;
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int f;
        cin >> f;
        q.push(f);

        if (cnt[f]++ == 0) types++;

        while (types > 2) {
            f = q.front();
            q.pop();

            if (--cnt[f] == 0) types--;
        }

        ans = max(ans, (int) q.size());
    }

    cout << ans << "\n";

    return 0;
}