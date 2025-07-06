#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m;
// bfs
int map[11][11];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pii> q;
// 크루스칼
vector<pair<int, pii>> edge;
int parent[7];

bool isin(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int x, int y, int n) {
    q.push({x, y});
    map[x][y] = n;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isin(nx, ny) && map[nx][ny] == -1) {
                map[nx][ny] = n;
                q.push({nx, ny});
            }
        }
    }
}

void make_edge(int x, int y, int d) {
    int sum = 0;
    int group = map[x][y];
    int nx = x, ny = y;

    while (true) {
        nx += dx[d];
        ny += dy[d];
        if (!isin(nx, ny) || map[nx][ny] == group) return;

        if (map[nx][ny] == 0) sum++;
        else {
            if (sum >= 2) edge.push_back({sum, {group, map[nx][ny]}});
            return;
        }
    }
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    
    parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) map[i][j] = -1;
        }
    }

    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == -1) bfs(i, j, num++); 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                if (map[i][j] != 0) make_edge(i, j, k);
            }
        }
    }

    sort(edge.begin(), edge.end());
    for (int i = 0; i < 7; i++) parent[i] = i;

    int sum = 0;
    for (auto i : edge) {
        int len = i.first;
        int a = i.second.first;
        int b = i.second.second;

        if (find(a) != find(b)) {
            sum += len;
            Union(a, b);
        }
    }

    int p = find(1);
    for (int i = 2; i < num; i++) {
        if (find(i) != p) sum = 0;
    }

    if (sum == 0) cout << "-1\n";
    else cout << sum << "\n";

    return 0;
}