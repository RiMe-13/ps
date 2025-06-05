#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, cnt;
int map[26][26];
bool visited[26][26];
vector<int> v;
queue<pii> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isin(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int x, int y) {
    cnt = 1;
    visited[x][y] = true;
    q.push({x, y});

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (isin(nx, ny) && !visited[nx][ny] && map[nx][ny] == 1) {
                visited[nx][ny] = true;
                cnt++;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            map[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                bfs(i, j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int i : v) cout << i << "\n";

    return 0;
}