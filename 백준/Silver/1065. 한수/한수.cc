#include <iostream>

using namespace std;

int n;

int solve(int num) {
    if (num < 100) return num;

    int cnt = 99;
    for (int i = 100; i <= num; i++) {
        int first = i / 100;
        int second = (i / 10) % 10;
        int third = i % 10;

        if ((first - second) == (second - third)) cnt++;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cout << solve(n) << "\n";

    return 0;
}