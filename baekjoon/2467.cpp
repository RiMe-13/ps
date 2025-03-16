#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int left = 0, right = n - 1;
    int res_sum = 2147483647;
    pair<int, int> res;

    while (left < right) {
        int sum = v[left] + v[right];
        if (abs(sum) < res_sum) {
            res_sum = abs(sum);
            res = {v[left], v[right]};
        }

        if (sum < 0) left++;
        else right--;
    }
    cout << res.first << " " << res.second << "\n";

    return 0;
}