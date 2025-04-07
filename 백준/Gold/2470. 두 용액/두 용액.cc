#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int ans[2];
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
    sort(v.begin(), v.end());

    int s = 0, e = n - 1;
    int min_val = 2147483647;
    while (s < e) {
        int sum = v[s] + v[e];

        if (min_val > abs(sum)) {
            min_val = abs(sum);
            ans[0] = v[s];
            ans[1] = v[e];

            if (sum == 0) break;
        }

        if (sum < 0) s++;
        else e--;
    }

    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}