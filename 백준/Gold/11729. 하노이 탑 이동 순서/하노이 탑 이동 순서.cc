#include <iostream>

using namespace std;

int n;

void hanoi(int n, int start, int to, int by) {
    if (n == 1) cout << start << " " << to << "\n";
    else {
        hanoi(n - 1, start, by, to);
        cout << start << " " << to << "\n";
        hanoi(n - 1, by, to, start);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cout << (1 << n) - 1 << "\n";
    hanoi(n, 1, 3, 2);

    return 0;
}