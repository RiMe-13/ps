#include <iostream>

using namespace std;

char arr[5][16];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; i++) cin >> arr[i];

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[j][i]) cout << arr[j][i];
        }
    }
    cout << "\n";

    return 0;
}