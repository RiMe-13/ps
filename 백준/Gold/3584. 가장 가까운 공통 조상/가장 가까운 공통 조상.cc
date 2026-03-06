#include <iostream>
#include <cstring>

using namespace std;

int t, n;
int parent[10001];
bool visited[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> n;

        for (int i = 1; i <= n; i++) parent[i] = i;
        memset(visited, false, sizeof(visited));
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            parent[b] = a;
        }

        int a, b;
        cin >> a >> b;
        visited[a] = true;

        while (a != parent[a]) {
            a = parent[a];
            visited[a] = true;
        }
        while (true) {
            if (visited[b]) {
                cout << b << "\n";
                break;
            }
            b = parent[b];
        }
    }

    return 0;
}