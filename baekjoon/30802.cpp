#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, t, p;
    int ts[6];
    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> ts[i];
    }
    cin >> t >> p;
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += (ts[i] / t);
        if (ts[i] % t) sum++;
    }
    cout << sum << "\n";
    cout << n / p << " " << n % p << "\n";

    return 0;
}