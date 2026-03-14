#include <iostream>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    if (n == 1) {
        for (int i = 2; i < 9; i++) {
            cin >> n;
            if (i != n) {
                cout << "mixed\n";
                break;
            }
            if (n == 8) cout << "ascending\n";
        }
    }
    else if (n == 8) {
        for (int i = 7; i > 0; i--) {
            cin >> n;
            if (i != n) {
                cout << "mixed\n";
                break;
            }
            if (n == 1) cout << "descending\n";
        }
    }
    else cout << "mixed\n";

    return 0;
}