#include <iostream>

using namespace std;

bool a[42];
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        if (!a[x % 42]) cnt++;
        a[x % 42] = true;
    }
    cout << cnt << "\n";

    return 0;
}