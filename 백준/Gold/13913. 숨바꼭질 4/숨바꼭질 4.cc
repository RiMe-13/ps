#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, k;
int dp[200005]; // dp[i] : 숫자 i에 대한 부모 값
bool visited[200005];
queue<pii> q;
vector<int> v;

bool isin(int x) {
    return x >= 0 && x <= 200000;
}

void bfs() {
    q.push({n, 0});

    while (!q.empty()) {
        int x = q.front().first;
        int time = q.front().second;
        visited[x] = true;
        q.pop();

        if (x == k) {
            int idx = x;
            while (idx != n) {
                v.push_back(idx);
                idx = dp[idx];
            }
            cout << time << "\n";
            break;
        }

        if (isin(x - 1) && !visited[x - 1]) {
            q.push({x - 1, time + 1});
            visited[x - 1] = true;
            dp[x - 1] = x;
        }
        if (isin(x + 1) && !visited[x + 1]) {
            q.push({x + 1, time + 1});
            visited[x + 1] = true;
            dp[x + 1] = x;
        }
        if (isin(x * 2) && !visited[x * 2]) {
            q.push({x * 2, time + 1});
            visited[x * 2] = true;
            dp[x * 2] = x;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    bfs();
    v.push_back(n);
    for (auto i = v.rbegin(); i != v.rend(); i++) {
        cout << *i << " ";
    }
    cout << "\n";

    return 0;
}