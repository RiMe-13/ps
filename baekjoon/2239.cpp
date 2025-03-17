#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int map[10][10];
vector<pii> v;

bool isPossible(int x, int y, int n) {
    for (int i = 0; i < 9; i++) {
        if (map[x][i] == n && i != y) return false;
        if (map[i][y] == n && i != x) return false;

        int nx = x / 3 * 3 + i / 3;
        int ny = y / 3 * 3 + i % 3;
        if (map[nx][ny] == n && !(nx == x && ny == y)) return false;

    }
    return true;
}

void backtrack(int i) {
    if (i == v.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cout << map[i][j];
            cout << "\n";
        }
        exit(0);
    }

    int x = v[i].first;
    int y = v[i].second;
    for (int n = 1; n < 10; n++) {
        if (isPossible(x, y, n)) {
            map[x][y] = n;
            backtrack(i + 1);
            map[x][y] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++) {
            map[i][j] = s[j] - '0';
            if (!map[i][j]) v.push_back({i, j});
        }
    }

    backtrack(0);

    return 0;
}