#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m = -1;
    int max_idx = -1;
    for (int i = 1; i <= 9; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > m) {
            m = tmp;
            max_idx = i;
        }
    }
    cout << m << "\n" << max_idx << "\n";

    return 0;
}