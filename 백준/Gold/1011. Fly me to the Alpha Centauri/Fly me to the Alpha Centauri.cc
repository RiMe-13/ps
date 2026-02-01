#include <iostream>
#include <cmath>

using namespace std;

int t;
long long x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> x >> y;
        long long max_val = 0;

        while (max_val * max_val <= y - x) max_val++;
        max_val--;
        long long move = max_val * 2 - 1;
        long long res = y - x - max_val * max_val;
        res = (long long) ceil((double) res / (double) max_val);
        move += res;

        cout << move << "\n";
    }

    return 0;
}