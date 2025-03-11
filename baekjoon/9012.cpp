#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int t = 0; t < n; t++) {
        q = {};
        bool flag = false;
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') q.push(1);
            else {
                if (q.empty()) {
                    cout << "NO\n";
                    flag = true;
                    break;
                }
                q.pop();
            }
        }
        if (flag) continue;
        if (q.empty()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}