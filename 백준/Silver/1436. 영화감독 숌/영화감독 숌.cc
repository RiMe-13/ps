#include <iostream>
#include <string>

using namespace std;

int n;

int solve() {
    int i = 666;
    int s = 0;

    while (true) {
        string str = to_string(i);
        for (int j = 0; j < str.length() - 2; j++) {
            if (str[j] == '6' && str[j + 1] == '6' && str[j + 2] == '6') {
                s++;
                if (s == n) return i;
                break;
            }
        }
        i++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cout << solve() << "\n";

    return 0;
}