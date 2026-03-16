#include <iostream>
#include <string>

using namespace std;

string s;
int l;
long long m = 1234567891, r = 1, res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> l;
    cin >> s;
    for (char c : s) {
        res += ((long long) (c - 96) * r) % m;
        r = (r * 31) % m;
    }
    cout << res << "\n";

    return 0;
}