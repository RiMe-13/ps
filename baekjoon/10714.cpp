#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int a[2001];
long long dp[2001][2001]; // dp[l][r] : l부터 r까지 사용했을 때의 joi가 얻는 최대 비용

long long joi(int left, int right);

long long ioi(int left, int right) {
    if ((right + 1) % n == left) return 0;
    if (a[(left + n - 1) % n] > a[(right + 1) % n]) return joi((left + n - 1) % n, right);
    return joi(left, (right + 1) % n);
}

long long joi(int left, int right) {
    long long result;
    if (dp[left][right] != -1) return dp[left][right];
    if ((right + 1) % n == left) return dp[left][right] = 0;
    long long res1 = a[(left + n - 1) % n] + ioi((left + n - 1) % n, right);
    long long res2 = a[(right + 1) % n] + ioi(left, (right + 1) % n);
    return dp[left][right] = max(res1, res2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));
    long long ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, a[i] + ioi(i, i));
    cout << ans << "\n";

    return 0;
}