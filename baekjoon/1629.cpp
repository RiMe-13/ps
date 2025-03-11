#include <iostream>

using namespace std;

int a, b, c;

long long pow(int b) {
    if (b == 1) return a % c;

    long long k = pow(b / 2) % c;
    if (b % 2 == 0) return k * k % c;
    else return ((k * k % c) * (a % c)) % c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    cout << pow(b) << "\n";

    return 0;
}