#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1;
    cin >> s2;
    int len1 = s1.length();
    int len2 = s2.length();

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string res = "";
    int i = len1, j = len2;
    while (i >= 1 && j >= 1) {
        if (dp[i][j] > dp[i - 1][j] && dp[i - 1][j] == dp[i][j - 1] && dp[i][j - 1] == dp[i - 1][j - 1]) {
            res += s2[j - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1] && dp[i - 1][j] == dp[i][j]) {
            i--;
        } else if (dp[i - 1][j] < dp[i][j - 1] && dp[i][j - 1] == dp[i][j]) {
            j--;
        }
        else {
            j--;
        }
    }
    reverse(res.begin(), res.end());

    cout << dp[len1][len2] << "\n";
    cout << res << "\n";

    return 0;
}