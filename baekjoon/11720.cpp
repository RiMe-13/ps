#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string s;
    cin >> n;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (s[i] - '0');
    }
    cout << sum << "\n";

    return 0;
}