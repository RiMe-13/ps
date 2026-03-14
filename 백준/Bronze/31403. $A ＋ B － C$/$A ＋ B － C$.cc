#include <iostream>
#include <string>

using namespace std;

string a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    cout << stoi(a) + stoi(b) - stoi(c) << "\n";
    cout << stoi(a + b) - stoi(c) << "\n";

    return 0;
}