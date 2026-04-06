#include <iostream>
#include <string>

using namespace std;

string s1, s2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> s1 >> s2) {
        int s1_idx = 0;
        bool is_sub = false;
        for (int i = 0; i < s2.length(); i++) {
            if (s1[s1_idx] == s2[i]) s1_idx++;
            if (s1_idx == s1.length()) {
                is_sub = true;
                break;
            }
        }

        if (is_sub) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}