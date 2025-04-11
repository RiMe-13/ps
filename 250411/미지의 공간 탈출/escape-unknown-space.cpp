#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct state {
    int d, x, y;
};
struct Time {
    int x, y, d, v;
};

int n, m, f;
int start_x, start_y;
int map[6][21][21];
int time_dist[6][21][21];
int machine_dist[6][21][21];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
state time_machine, exit_p;
Time t[11];

bool isin(int d, int x, int y) {
    int len = (d == 5) ? n : m;
    return (x >= 0 && x < len && y >= 0 && y < len);
}

state change_dim(int d, int x, int y) {
    state new_s = {-1, -1, -1};
    int len = m;

    if (d == 0) {
        if (y == len) new_s = {3, x, 0};
        if (y < 0) new_s = {2, x, len - 1};
        if (x == len) new_s = {5, start_x + (len - 1 - y), start_y + len};
        if (x < 0) new_s = {4, len - 1 - y, len - 1};
    }
    else if (d == 1) {
        if (y == len) new_s = {2, x, 0};
        if (y < 0) new_s = {3, x, len - 1};
        if (x == len) new_s = {5, start_x + y, start_y - 1};
        if (x < 0) new_s = {4, y, 0};
    }
    else if (d == 2) {
        if (y == len) new_s = {0, y, 0};
        if (y < 0) new_s = {1, x, len - 1};
        if (x == len) new_s = {5, start_x + len, start_y + y};
        if (x < 0) new_s = {4, len - 1, y};
    }
    else if (d == 3) {
        if (y == len) new_s = {1, x, 0};
        if (y < 0) new_s = {0, x, len - 1};
        if (x == len) new_s = {5, start_x - 1, start_y + (len - 1 - y)};
        if (x < 0) new_s = {4, 0, len - 1 - y};
    }
    else if (d == 4) {
        if (y == len) new_s = {0, 0, len - 1 - x};
        if (y < 0) new_s = {1, 0, x};
        if (x == len) new_s = {2, 0, y};
        if (x < 0) new_s = {3, 0, len - 1 - y};
    }

    return new_s;
}

state go_next(int d, int x, int y, int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (d >= 0 && d < 5) {
        if (isin(d, nx, ny)) return {d, nx, ny};
        else return change_dim(d, nx, ny);
    }
    else {
        if (isin(d, nx, ny) && map[d][nx][ny] != 3) return {d, nx, ny};
        else return {d, x, y};
    }
}

void time_bfs() {
    queue<Time> q;
    for (int i = 0; i < f; i++) {
        q.push(t[i]);
        time_dist[5][t[i].x][t[i].y] = 0;
    }

    while (!q.empty()) {
        Time cur = q.front();
        q.pop();

        state next = go_next(5, cur.x, cur.y, cur.d);
        if (cur.x == next.x && cur.y == next.y) continue;

        if (map[5][next.x][next.y] == 0) {
            if (time_dist[5][next.x][next.y] == -1) time_dist[5][next.x][next.y] = time_dist[5][cur.x][cur.y] + cur.v;
            time_dist[5][next.x][next.y] = min(time_dist[5][next.x][next.y], time_dist[5][cur.x][cur.y] + cur.v);

            q.push({next.x, next.y, cur.d, cur.v});
        }
    }
}

void bfs() {
    queue<state> q;
    q.push(time_machine);
    machine_dist[time_machine.d][time_machine.x][time_machine.y] = 0;

    while (!q.empty()) {
        state cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            state next = go_next(cur.d, cur.x, cur.y, i);
            if (map[next.d][next.x][next.y] == 1 || machine_dist[next.d][next.x][next.y] != -1) continue;
            if (next.d == 5 && time_dist[next.d][next.x][next.y] != -1 && time_dist[next.d][next.x][next.y] <= machine_dist[cur.d][cur.x][cur.y] + 1) continue;

            machine_dist[next.d][next.x][next.y] = machine_dist[cur.d][cur.x][cur.y] + 1;
            q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(time_dist, -1, sizeof(time_dist));
    memset(machine_dist, -1, sizeof(machine_dist));

    cin >> n >> m >> f;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[5][i][j];
            if (map[5][i][j] == 4) exit_p = {5, i, j};
            if (map[5][i][j] == 3 && flag == false) {
                start_x = i;
                start_y = j;
                flag = true;
            }
        }
    }
    for (int d = 0; d < 5; d++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[d][i][j];
                if (map[d][i][j] == 2) time_machine = {d, i, j};
            }
        }
    }
    for(int i = 0; i < f; i++) cin >> t[i].x >> t[i].y >> t[i].d >> t[i].v;

    time_bfs();
    bfs();
    cout << machine_dist[exit_p.d][exit_p.x][exit_p.y] << "\n";

    return 0;
}