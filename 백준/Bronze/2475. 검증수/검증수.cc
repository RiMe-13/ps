#include <iostream>

using namespace std;

int n, sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; i++) {
        cin >> n;
        sum += n * n;
    }
    cout << sum % 10 << "\n";

    return 0;
}