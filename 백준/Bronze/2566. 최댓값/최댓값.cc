#include <iostream>

using namespace std;

int tmp, r, c, max_val = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            cin >> tmp;
            if (tmp > max_val) {
                max_val = tmp;
                r = i;
                c = j;
            }
        }
    }
    cout << max_val << "\n";
    cout << r << " " << c << "\n";

    return 0;
}