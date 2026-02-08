#include <iostream>

using namespace std;

int a, b, c, res;
int cnt[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    res = a * b * c;
    while (res) {
        cnt[res % 10]++;
        res /= 10;
    }

    for (int i = 0; i < 10; i++) cout << cnt[i] << "\n";

    return 0;
}