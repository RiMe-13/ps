#include <iostream>

using namespace std;

int n, min_val = 1e9;
int s[20][20];
bool selected[20];

void calc() {
    int a = 0, b = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (selected[i] && selected[j]) a += s[i][j];
            else if (!selected[i] && !selected[j]) b += s[i][j];
        }
    }

    min_val = min(min_val, abs(a - b));
}

void select(int cnt, int idx) {
    if (cnt == n / 2) calc();

    for (int i = idx; i < n; i++) {
        selected[i] = true;
        select(cnt + 1, i + 1);
        selected[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }

    select(0, 0);

    cout << min_val << "\n";

    return 0;
}