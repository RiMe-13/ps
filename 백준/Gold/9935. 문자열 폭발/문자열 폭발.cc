#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, tmp = "";
    cin >> a;
    cin >> b;
    for (int i = 0; i < a.length(); i++) {
        tmp += a[i];
        if (tmp.length() >= b.length()) {
            bool flag = true;

            for (int j = 0; j < b.length(); j++) {
                if (tmp[tmp.length() - b.length() + j] != b[j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) tmp.erase(tmp.end() - b.length(), tmp.end());
        }
    }

    if (tmp.empty()) cout << "FRULA\n";
    else cout << tmp << "\n";

    return 0;
}