#include <iostream>
#include <numeric>

using namespace std;

long long a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    cout << a * b / gcd(a, b) << "\n";

    return 0;
}