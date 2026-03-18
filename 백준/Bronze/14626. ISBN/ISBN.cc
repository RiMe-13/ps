#include <iostream>
#include <string>

using namespace std;

string isbn;
int sum;
bool star_even;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> isbn;
    
    for (int i = 0; i < 13; i++) {
        bool even = i % 2;

        if (isbn[i] == '*') star_even = even;
        else sum += (isbn[i] - '0') * (even ? 3 : 1);
    }

    sum %= 10;

    if (star_even) {
        for (int i = 0; i < 10; i++) {
            if ((sum + i * 3) % 10 == 0) {
                cout << i << "\n";
                break;
            }
        }
    }
    else cout << (10 - sum) % 10 << "\n";

    return 0;
}