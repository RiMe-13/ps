#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i : v) cout << i;
    cout << "\n";

    return 0;
}