#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<long long, long long> pll;

int n;
vector<pll> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int x1, y1;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (i == 0) {
            x1 = x;
            y1 = y;
        }
        v.push_back({x, y});
    }
    v.push_back({x1, y1});

    long double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (v[i].first * v[i + 1].second);
        sum -= (v[i].second * v[i + 1].first);
    }
    sum = abs(sum);
    sum /= 2;
    cout << fixed;
    cout.precision(1);
    cout << sum << "\n";

    return 0;
}