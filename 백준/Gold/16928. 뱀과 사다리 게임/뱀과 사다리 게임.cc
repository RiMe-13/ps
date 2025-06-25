#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, m;
int map[101];
bool visited[101];
queue<pii> q;

void bfs(int s, int c) {
    q.push({s, c});

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int nx = cur + i;
            if (nx == 100) {
                cout << cnt + 1 << "\n";
                return;
            }
            else if (nx < 100) {
                while (map[nx] != 0) nx = map[nx];

                if (!visited[nx]) {
                    q.push({nx, cnt + 1});
                    visited[nx] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        map[a] = b;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        map[a] = b;
    }

    bfs(1, 0);

    return 0;
}