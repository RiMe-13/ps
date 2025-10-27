#include <iostream>

using namespace std;

long long fact(long long n) {
    if (n == 0 || n == 1) return 1;
    return n * fact(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    cout << fact(n) << "\n";

    return 0;
}