#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x, cnt;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> x;
    sort(v.begin(), v.end());

    int s = 0, e = n - 1;
    while (s < e) {
        int sum = v[s] + v[e];
        if (sum == x) cnt++;

        if (sum <= x) s++;
        else e--;
    }
    cout << cnt << "\n";

    return 0;
}