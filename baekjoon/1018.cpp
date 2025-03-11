#include <iostream>
#include <algorithm>

using namespace std;

string bw[8] = {
    "BWBWBWBW", 
    "WBWBWBWB", 
    "BWBWBWBW", 
    "WBWBWBWB", 
    "BWBWBWBW", 
    "WBWBWBWB", 
    "BWBWBWBW", 
    "WBWBWBWB"
};
string wb[8] = {
    "WBWBWBWB", 
    "BWBWBWBW", 
    "WBWBWBWB", 
    "BWBWBWBW", 
    "WBWBWBWB", 
    "BWBWBWBW", 
    "WBWBWBWB", 
    "BWBWBWBW"
};
string board[51];
int n, m;

int cnt_bw(int x, int y) {
    int cnt = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[x + i][y + j] != bw[i][j]) cnt++;
        }
    }

    return cnt;
}

int cnt_wb(int x, int y) {
    int cnt = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[x + i][y + j] != wb[i][j]) cnt++;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];

    int min_val = 1e9;
    for (int i = 0; i + 8 <= n; i++) {
        for (int j = 0; j + 8 <= m; j++) {
            int val = min(cnt_bw(i, j), cnt_wb(i, j));
            min_val = min(min_val, val);
        }
    }
    cout << min_val << "\n";

    return 0;
}