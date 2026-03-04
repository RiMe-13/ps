#include <string>
#include <vector>

using namespace std;

int answer;
int num[5];

void solve(int depth, int cur, int n, vector<vector<int>> &q, vector<int> &ans) {
    if (depth == 5) {
        int secret_cnt[10] = {0, };
        for (int i = 0; i < q.size(); i++) {
            int tmp_cnt = 0;
            
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (q[i][j] == num[k]) tmp_cnt++;
                }
            }
            secret_cnt[i] = tmp_cnt;
        }
        
        bool flag = true;
        for (int i = 0; i < q.size(); i++) {
            if (secret_cnt[i] != ans[i]) {
                flag = false;
                break;
            }
        }
        
        if (flag) answer++;
        return;
    }
    
    for (int i = cur; i <= n; i++) {
        num[depth] = i;
        solve(depth + 1, i + 1, n, q, ans);
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    solve(0, 1, n, q, ans);
    return answer;
}