#include <iostream>
#include <queue>

using namespace std;

int n, max_val;
int board[21][21];
//int copy_board[21][21];

void shift(int x) {
    queue<int> q;

    // 왼쪽 이동
    if (x == 0) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][j]) q.push(board[i][j]);
                board[i][j] = 0;
            }
            int idx = 1;

            while (!q.empty()) {
                int k = q.front();
                q.pop();

                if (!board[i][idx]) board[i][idx] = k;
                else if (board[i][idx] == k) board[i][idx++] *= 2;
                else board[i][++idx] = k;
            }
        }
    }
    // 오른쪽 이동
    else if (x == 1) { 
        for (int i = 1; i <= n; i++) {
            for (int j = n; j >= 1; j--) {
                if (board[i][j]) q.push(board[i][j]);
                board[i][j] = 0;
            }
            int idx = n;

            while (!q.empty()) {
                int k = q.front();
                q.pop();

                if (!board[i][idx]) board[i][idx] = k;
                else if (board[i][idx] == k) board[i][idx--] *= 2;
                else board[i][--idx] = k;
            }
        }
    }
    // 위쪽 이동
    else if (x == 2) {
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= n; i++) {
                if (board[i][j]) q.push(board[i][j]);
                board[i][j] = 0;
            }
            int idx = 1;

            while (!q.empty()) {
                int k = q.front();
                q.pop();

                if (!board[idx][j]) board[idx][j] = k;
                else if (board[idx][j] == k) board[idx++][j] *= 2;
                else board[++idx][j] = k;
            }
        }
    }
    // 아래쪽 이동
    else {
        for (int j = 1; j <= n; j++) {
            for (int i = n; i >= 1; i--) {
                if (board[i][j]) q.push(board[i][j]);
                board[i][j] = 0;
            }
            int idx = n;

            while (!q.empty()) {
                int k = q.front();
                q.pop();

                if (!board[idx][j]) board[idx][j] = k;
                else if (board[idx][j] == k) board[idx--][j] *= 2;
                else board[--idx][j] = k;
            }
        }
    }
}

void dfs(int depth) {
    if (depth == 5) return;
    
    int copy_board[21][21];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            copy_board[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        shift(i);

        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (max_val < board[j][k]) max_val = board[j][k];
            }
        }

        dfs(depth + 1);

        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                board[j][k] = copy_board[j][k];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0);
    cout << max_val << "\n";

    return 0;
}