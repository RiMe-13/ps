#include <iostream>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

typedef pair<int, int> pii;

int t, h, w, cnt;
string k;
char map[103][103];
bool visited[103][103];
bool key[26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isin(int x, int y) {
    return x >= 0 && x <= h + 1 && y >= 0 && y <= w + 1;
}

void bfs(int x, int y) {
    queue<pii> q;
    queue<pii> door[26];

    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        pii v = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = v.first + dx[i];
            int yy = v.second + dy[i];
    
            if (isin(xx, yy)) {
                if (map[xx][yy] == '*' || visited[xx][yy]) continue;
                visited[xx][yy] = true;

                if (map[xx][yy] >= 'A' && map[xx][yy] <= 'Z') {
                    if (key[map[xx][yy] - 'A']) q.push({xx, yy});
                    else door[map[xx][yy] - 'A'].push({xx, yy});
                }
                else if (map[xx][yy] >= 'a' && map[xx][yy] <= 'z') {
                    q.push({xx, yy});
                    if (!key[map[xx][yy] - 'a']) {
                        key[map[xx][yy] - 'a'] = true;

                        while (!door[map[xx][yy] - 'a'].empty()) {
                            q.push(door[map[xx][yy] - 'a'].front());
                            door[map[xx][yy] - 'a'].pop();
                        }
                    }
                }
                else {
                    q.push({xx, yy});
                    if (map[xx][yy] == '$') cnt++;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        memset(key, false, sizeof(key));
        k.clear();
        cnt = 0;

        cin >> h >> w;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) cin >> map[i][j];
        }
        cin >> k;
        if (k != "0") {
            for (int i = 0; i < k.length(); i++) {
                key[k[i] - 'a'] = true;
            }
        }
        bfs(0, 0);
        cout << cnt << "\n";
    }

    return 0;
}