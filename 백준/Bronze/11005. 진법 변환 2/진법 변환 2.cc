#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, b;
string res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> b;
    while (n > 0) {
        int tmp = n % b;

        if (tmp < 10) res += (tmp + '0');
        else res += (tmp - 10 + 'A');

        n /= b;
    }

    reverse(res.begin(), res.end());
    cout << res << "\n";

    return 0;
}