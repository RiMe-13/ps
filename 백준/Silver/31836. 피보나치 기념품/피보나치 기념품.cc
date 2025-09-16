#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n > 1) {
        if (n >= 3) {
            a.push_back(n);
            b.push_back(n - 1);
            b.push_back(n - 2);
            n -= 3;
        }
        if (n == 2) {
            a.push_back(2);
            b.push_back(1);
            n -= 2;
        }
    }

    cout << a.size() << "\n";
    for (int i : a) cout << i << " ";
    cout << "\n";
    cout << b.size() << "\n";
    for (int i : b) cout << i << " ";
    cout << "\n";

    return 0;
}