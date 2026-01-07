#include <iostream>
#include <string>

using namespace std;

string s;
int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    for (auto i : s) {
        if (i >= 'A' && i <= 'C') t += 3;
        else if (i >= 'D' && i <= 'F') t += 4;
        else if (i >= 'G' && i <= 'I') t += 5;
        else if (i >= 'J' && i <= 'L') t += 6;
        else if (i >= 'M' && i <= 'O') t += 7;
        else if (i >= 'P' && i <= 'S') t += 8;
        else if (i >= 'T' && i <= 'V') t += 9;
        else t += 10;

    }
    cout << t << "\n";

    return 0;
}