#include <iostream>

using namespace std;

int n, cnt;
int weight[31];
bool dp[31][15001]; // dp[i][w] : i번째까지의 추를 사용했을 때 w 만큼의 무게를 만들 수 있는지 여부

void solve(int i, int w) {
    if (i > n || dp[i][w]) return;
    dp[i][w] = true;
    solve(i + 1, w + weight[i]);
    solve(i + 1, abs(w - weight[i]));
    solve(i + 1, w);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> weight[i];
    solve(0, 0);

    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int x;
        cin >> x;

        if (x > 15000) cout << "N ";
        else if (dp[n][x]) cout << "Y ";
        else cout << "N ";
    }
    cout << "\n";

    return 0;
}