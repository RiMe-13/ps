#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a, b;
int x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    x = stoi(a), y = stoi(b);
    cout << max(x, y) << "\n";

    return 0;
}