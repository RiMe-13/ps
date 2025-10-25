#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
double mean, median, mode, range;
int cnt[8001];
vector<double> v, mv;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        double tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (double i : v) mean += i;
    mean = round(mean / n);
    if (mean == -0) mean = 0;

    sort(v.begin(), v.end());
    if (n == 1) median = v[0];
    else median = v[(n - 1) / 2];

    for (int i = 0; i < n; i++) cnt[int(v[i]) + 4000]++;

    int max_val = cnt[0];
    for (int i = 1; i < 8001; i++) {
        max_val = max(max_val, cnt[i]);
    }
    for (int i = 0; i < 8001; i++) {
        if (max_val == cnt[i]) mv.push_back(i - 4000);
    }

    sort(mv.begin(), mv.end());
    if (mv.size() == 1) mode = mv[0];
    else mode = mv[1];

    range = v[n - 1] - v[0];

    cout << mean << "\n";
    cout << median << "\n";
    cout << mode << "\n";
    cout << range << "\n";

    return 0;
}