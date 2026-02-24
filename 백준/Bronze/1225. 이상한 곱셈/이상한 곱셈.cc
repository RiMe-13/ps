#include <iostream>

using namespace std;

string a, b;
long long sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    for (char i : a) {
        for (char j : b) {
            sum += (long long) (i - '0') * (long long) (j - '0'); 
        }
    }
    cout << sum << "\n";

    return 0;
}