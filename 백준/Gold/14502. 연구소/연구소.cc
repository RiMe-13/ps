#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, m, ans;
int m1[8][8], m2[8][8];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<pii> init_virus;

void copy(int src[8][8], int dst[8][8]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dst[i][j] = src[i][j];
        }
    }
}

bool isin(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void spread() {
    queue<pii> q;
    for (pii i : init_virus) q.push(i);

    while (!q.empty()) {
        pii cur = q.front();
        int x = cur.first, y = cur.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (isin(nx, ny) && m2[nx][ny] == 0) {
                m2[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (m2[i][j] == 0) cnt++;
        }
    }
    ans = max(ans, cnt);
}

void generate(int cnt, int start) {
    if (cnt == 3) {
        copy(m1, m2);
        spread();
    }
    else {
        for (int i = start; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (m1[i][j] == 0) {
                    m1[i][j] = 1;
                    generate(cnt + 1, i);
                    m1[i][j] = 0;
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
        for (int j = 0; j < m; j++) {
            cin >> m1[i][j];
            if (m1[i][j] == 2) init_virus.push_back({i, j});
        }
    }
    generate(0, 0);
    cout << ans << "\n";

    return 0;
}