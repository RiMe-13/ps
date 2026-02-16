#include <iostream>

using namespace std;

int init, n, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> init;
    n = init;
    
    do {
        n = (n % 10) * 10 + ((n / 10) + (n % 10)) % 10;
        cnt++;
    } while (init != n);

    cout << cnt << "\n";

    return 0;
}