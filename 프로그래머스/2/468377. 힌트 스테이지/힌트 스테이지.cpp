#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n, k;
int cnt[16]; // 각 스테이지별 힌트권 개수
int answer = 1e9;

void solve(int depth, int sum, vector<vector<int>> &cost, vector<vector<int>> &hint) {
    if (depth == n - 1) {
        int tmp = min(n - 1, cnt[depth]);
        sum += cost[depth][tmp];
        answer = min(answer, sum);
        return;
    }
    
    int tmp = min(n - 1, cnt[depth]);
    sum += cost[depth][tmp]; // 현재 단계에서의 해결 비용
    // 힌트권을 안 샀을 경우
    solve(depth + 1, sum, cost, hint);
    // 힌트권을 샀을 경우
    for (int i = 1; i < k; i++) cnt[hint[depth][i] - 1]++;
    sum += hint[depth][0];
    solve(depth + 1, sum, cost, hint);
    for (int i = 1; i < k; i++) cnt[hint[depth][i] - 1]--;
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    //int answer = 0;
    n = cost.size();
    k = hint[0].size();
    solve(0, 0, cost, hint);
    return answer;
}