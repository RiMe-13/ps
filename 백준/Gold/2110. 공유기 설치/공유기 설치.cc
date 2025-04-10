#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> v;

int binarySearch() {
    int s = 1, e = v[n - 1] - v[0];
    int ans = 0;

    while (s <= e) {
        int cnt = 1;
        int mid = (s + e) / 2;
        int st = v[0];

        for (int i = 1; i < n; i++) {
            if (v[i] - st >= mid) {
                cnt++;
                st = v[i];
            }
        }

        if (cnt >= c) {
            ans = max(ans, mid);
            s = mid + 1;
        }
        else e = mid - 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    cout << binarySearch() << "\n";
    
    return 0;
}