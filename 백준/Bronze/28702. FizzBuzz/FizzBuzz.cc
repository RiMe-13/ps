#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 3; ++i)
    {
        cin >> s;

        if (s[0] == 'F' || s[0] == 'B') continue;

        int num = stoi(s) + 3 - i;

        if (num % 3 == 0 && num % 5 == 0) cout << "FizzBuzz\n";
        else if (num % 3 == 0) cout << "Fizz\n";
        else if (num % 5 == 0) cout << "Buzz\n";
        else cout << num << "\n";

        break;
    }

    return 0;
}