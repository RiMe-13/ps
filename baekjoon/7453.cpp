#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[4001], b[4001], c[4001], d[4001];
vector<long long> sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    long long res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum.push_back(a[i] + b[j]);
        }
    }
    sort(sum.begin(), sum.end());
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            long long tmp = -(c[i] + d[j]);
            long long lower = lower_bound(sum.begin(), sum.end(), tmp) - sum.begin();
            long long upper = upper_bound(sum.begin(), sum.end(), tmp) - sum.begin();
            
            if (tmp == sum[lower]) res += (upper - lower);
        }
    }

    cout << res << "\n";

    return 0;
}