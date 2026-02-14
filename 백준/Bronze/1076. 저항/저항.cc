#include <iostream>
#include <string>

using namespace std;

string s;
string color[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
long long res;
long long a[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 3; i++) {
        cin >> s;
        for (int j = 0; j < 10; j++) {
            if (color[j] == s) a[i] = j;
        }
    }

    res = a[0] * 10 + a[1];
    for (int i = 0; i < a[2]; i++) res *= 10;
    cout << res << "\n";

    return 0;
}