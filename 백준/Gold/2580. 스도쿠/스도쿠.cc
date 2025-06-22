#include <iostream>

using namespace std;

int cnt, zero;
int board[10][10];
bool used[10];

void visit(int x, int y) {
    int nx = (x / 3) * 3, ny = (y / 3) * 3; 

    for (int i = 0; i < 10; i++) used[i] = false;
    for (int i = 0; i < 9; i++) {
        used[board[i][y]] = true;
        used[board[x][i]] = true;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            used[board[nx + i][ny + j]] = true;
        }
    }
}

bool check(int x, int y, int k) {
    int nx = (x / 3) * 3, ny = (y / 3) * 3; 

    for (int i = 0; i < 9; i++) {
        if (board[i][y] == k || board[x][i] == k) return false;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[nx + i][ny + j] == k) return false;
        }
    }

    return true;
}

bool solve(int n) {
    if (zero == cnt) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cout << board[i][j] << " ";
            cout << "\n";
        }
        return true;
    }

    int i = n / 9, j = n % 9;

    if (board[i][j] == 0) {
        for (int k = 1; k <= 9; k++) {
            visit(i, j);

            if (!used[k] && check(i, j, k)) {
                board[i][j] = k;
                used[k] = true;
                zero++;
                if (solve(n + 1)) return true;
                board[i][j] = 0;
                used[k] = false;
                zero--;
            }
        }
    }
    else return solve(n + 1);

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) cnt++;
        }
    }

    solve(0);

    return 0;
}