#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;
int p[51];
vector<pii> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back({tmp, i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) p[v[i].second] = i;

    for (int i = 0; i < n; i++) cout << p[i] << " ";
    cout << "\n";

    return 0;
}