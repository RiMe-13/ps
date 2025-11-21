#include <iostream>
#include <string>

using namespace std;

string n;
int b, sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> b;
    for (char i : n) {
        sum *= b;
        if (i >= '0' && i <= '9') sum += (i - '0');
        else sum += (i - 'A' + 10);
    }
    cout << sum << "\n";

    return 0;
}