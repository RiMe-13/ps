#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        getline(cin, s);
        if (s == "") break;
        cout << s << "\n";
    }

    return 0;
}