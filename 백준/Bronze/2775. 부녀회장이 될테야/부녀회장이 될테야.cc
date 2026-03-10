#include <iostream>

using namespace std;

int psum[15][15];
int t, n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 15; i++) {
        for (int j = 1; j < 15; j++) {
            if (i == 0) psum[i][j] = j;
            else if (j == 1) psum[i][j] = 1;
            else psum[i][j] = psum[i][j - 1] + psum[i - 1][j];
        }
    }

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> n >> k;
        cout << psum[n][k] << "\n";
    }

    return 0;
}