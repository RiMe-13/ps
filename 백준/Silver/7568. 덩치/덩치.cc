#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int n;
pii a[51];

bool cmp(pii x, pii y) {
    return x.first < y.first && x.second < y.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    for (int i = 0; i < n; i++) {
        int rank = 1;
        for (int j = 0; j < n; j++) {
            if (cmp(a[i], a[j])) rank++;
        }
        cout << rank << " ";
    }
    cout << "\n";

    return 0;
}