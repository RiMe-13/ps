#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, k;
int dist[100001];
int cnt[100001];
queue<int> q;

bool isin(int x) {
    return x >= 0 && x <= 100000;
}

void bfs(int x) {
    dist[x] = 0;
    cnt[x] = 1;
    q.push(x);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nx : {cur + 1, cur - 1, cur * 2}) {
            if (!isin(nx)) continue;

            if (dist[nx] != -1) {
                if (dist[nx] == dist[cur] + 1) cnt[nx] += cnt[cur];
            }
            else {
                dist[nx] = dist[cur] + 1;
                cnt[nx] = cnt[cur];
                q.push(nx);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    if (n == k) cout << "0\n1\n";
    else {
        memset(dist, -1, sizeof(dist));

        bfs(n);
        cout << dist[k] << "\n" << cnt[k] << "\n";
    }

    return 0;
}