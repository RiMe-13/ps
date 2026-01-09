#include <iostream>

using namespace std;

int b[6] = {1, 1, 2, 2, 2, 8};
int w[6];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 6; i++) {
        cin >> w[i];
        cout << b[i] - w[i] << " ";
    }
    cout << "\n";

    return 0;
}