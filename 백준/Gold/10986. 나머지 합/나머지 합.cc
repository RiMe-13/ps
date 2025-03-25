#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
vector<int> v;
unordered_map<int, long long> um;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    um[0] = 1;
    long long cnt = 0;
    long long sum = 0;
    for (int i : v) {
        sum += i;
        int mod = sum % m;
        sum %= m;

        cnt += um[mod];
        um[mod]++;
    }
    cout << cnt << "\n";

    return 0;
}