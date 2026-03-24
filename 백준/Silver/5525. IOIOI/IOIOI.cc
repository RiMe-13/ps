#include <iostream>
#include <string>

using namespace std;

string s;
int n, m, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> s;

    for (int i = 0; i < m; i++) {
        if (s[i] == 'O') continue;

        int k = 0;
        while (s[i + 1] == 'O' && s[i + 2] == 'I') {
            k++;

            if (k == n) {
                ans++;
                k--;
            }
            
            i += 2;
        }
    }

    cout << ans << "\n";

    return 0;
}