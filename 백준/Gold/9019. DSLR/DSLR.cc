#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int t, a, b;
bool visited[10001];
queue<pair<int, string>> q;

void bfs() {
    q.push({a, ""});
    visited[a] = true;

    while (!q.empty()) {
        int n = q.front().first;
        string op = q.front().second;
        q.pop();

        if (n == b) {
            cout << op << "\n";
            return;
        }

        int d, s, l, r;

        d = (n * 2) % 10000;
        if (!visited[d]) {
            q.push({d, op + "D"});
            visited[d] = true;
        }

        s = n - 1 < 0 ? 9999 : n - 1;
        if (!visited[s]) {
            q.push({s, op + "S"});
            visited[s] = true;
        }

        l = (n % 1000) * 10 + (n / 1000);
        if (!visited[l]) {
            q.push({l, op + "L"});
            visited[l] = true;
        }

        r = n / 10 + (n % 10) * 1000;
        if (!visited[r]) {
            q.push({r, op + "R"});
            visited[r] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        memset(visited, false, sizeof(visited));
        q = {};
        cin >> a >> b;
        bfs();
    }

    return 0;
}