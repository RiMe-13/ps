#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[4001][4001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1;
    cin >> s2;
    int len1 = s1.length(), len2 = s2.length();
    int ans = 0;
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            if (dp[i][j] > ans) ans = dp[i][j];
        }
    }

    cout << ans << "\n";

    return 0;
}