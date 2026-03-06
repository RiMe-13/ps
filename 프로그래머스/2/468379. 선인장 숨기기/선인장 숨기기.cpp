#include <vector>
#include <algorithm>

using namespace std;

int M, N, H, W;
vector<vector<int>> grid;
vector<vector<int>> psum;

// 시점 mid까지 비가 내렸을 때, h x w 크기의 빈 공간이 있는지 확인
bool check(int mid, const vector<vector<int>>& drops, int& resR, int& resC) {
    // 격자 초기화 및 빗방울 표시
    vector<vector<int>> current_grid(M + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < mid; ++i) {
        current_grid[drops[i][0] + 1][drops[i][1] + 1] = 1;
    }

    // 2차원 누적합 계산
    vector<vector<int>> s(M + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            s[i][j] = current_grid[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    // 모든 가능한 (r, c) 시작점에 대해 h x w 구역에 빗방울(1)이 0개인지 확인
    for (int i = 0; i <= M - H; ++i) {
        for (int j = 0; j <= N - W; ++j) {
            int r1 = i + 1, c1 = j + 1;
            int r2 = i + H, c2 = j + W;
            int count = s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] + s[r1 - 1][c1 - 1];
            
            if (count == 0) {
                resR = i;
                resC = j;
                return true;
            }
        }
    }
    return false;
}

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    M = m; N = n; H = h; W = w;
    int low = 0, high = drops.size();
    int ansR = 0, ansC = 0;
    int max_time = 0;

    // 이분 탐색을 통해 가장 늦게 비를 맞는 시점(최대 생존 시간)을 찾음
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int tempR, tempC;
        if (check(mid, drops, tempR, tempC)) {
            max_time = mid;
            ansR = tempR;
            ansC = tempC;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return {ansR, ansC};
}