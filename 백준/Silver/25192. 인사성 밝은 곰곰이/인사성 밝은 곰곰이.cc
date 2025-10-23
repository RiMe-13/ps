#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int n, cnt;
unordered_set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if (str == "ENTER") {
            cnt += s.size();
            s.clear();
        }
        else s.insert(str);
    }
    cnt += s.size();

    cout << cnt << "\n";

    return 0;
}