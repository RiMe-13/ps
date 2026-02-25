#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m;

bool binary_search(const vector<int>& v, int x) {
    int s = 0, e = n - 1;

    while (s <= e) {
        int mid = (s + e) / 2;
        if (v[mid] < x) s = mid + 1;
        else if (v[mid] == x) return true;
        else e = mid - 1;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            v[i] = tmp;
        }
        sort(v.begin(), v.end());

        cin >> m;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            if (binary_search(v, x)) cout << "1\n";
            else cout << "0\n";
        }
    }

    return 0;
}