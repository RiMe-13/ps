#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m = -1;
    int score[1001];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> score[i];
        if (score[i] > m) m = score[i];
    }

    double sum = 0;
    for (int i = 0; i < n; i++) sum += ((double) score[i] / (double) m * 100);
    cout << sum / n << "\n";

    return 0;
}