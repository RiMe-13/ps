#include <iostream>
#include <cstring>

using namespace std;

int n, w;
int a[5001], i1[400001], i2[400001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(i1, -1, sizeof(i1));
    memset(i2, -1, sizeof(i2));

    cin >> w >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int weight = a[i] + a[j];
            if (i1[weight] == -1) {
                i1[weight] = i;
                i2[weight] = j;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int weight = w - a[i] - a[j];
            if (weight < 0 || weight > 400000 || i1[weight] == -1) continue;
            if (i1[weight] != i && i1[weight] != j && i2[weight] != i && i2[weight] != j) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";

    return 0;
}