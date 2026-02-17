#include <iostream>
#include <string>

using namespace std;

string a, b;
int ans = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    for (int i = 0; i <= b.length() - a.length(); i++) {
        int cnt = 0;
        for (int j = 0; j < a.length(); j++) {
            if (a[j] != b[i + j]) cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << "\n";

    return 0;
}