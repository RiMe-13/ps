#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, house;
char maze[51][51];
int height[51][51];
bool visited[51][51];
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
pair<int, int> post;
vector<int> h;

bool bfs(int left, int right) {
    queue<pair<int, int>> q;
    if (height[post.first][post.second] >= h[left] && height[post.first][post.second] <= h[right]) {
        q.push({ post.first, post.second });
        visited[post.first][post.second] = true;
    }
    int cnt = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < n) {
                if (visited[new_x][new_y] == false && height[new_x][new_y] >= h[left] && height[new_x][new_y] <= h[right]) {
                    visited[new_x][new_y] = true;
                    q.push({ new_x, new_y });
                    if (maze[new_x][new_y] == 'K') cnt++;
                }
            }
        }
    }

    if (cnt == house) return true;
    else return false;
}

int two_pointer() {
    int l = 0, r = 0;
    int result = 2147483647;

    while (l < h.size()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }

        bool possible = bfs(l, r);
        if (possible) {
            if (result > h[r] - h[l]) result = h[r] - h[l];
            l++;
        }
        else {
            if (r < h.size() - 1) r++;
            else break;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cin >> maze[i][j];
            if (maze[i][j] == 'P') post = { i, j };
            else if (maze[i][j] == 'K') house++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cin >> height[i][j];
            h.push_back(height[i][j]);
        }
    }

    sort(h.begin(), h.end());
    h.erase(unique(h.begin(), h.end()), h.end());

    cout << two_pointer() << "\n";

    return 0;
}