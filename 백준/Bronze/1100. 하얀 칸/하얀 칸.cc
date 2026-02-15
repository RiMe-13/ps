#include <iostream>

using namespace std;

char map[8][8];
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> map[i][j];
            if ((i + j) % 2 == 0 && map[i][j] == 'F') cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}