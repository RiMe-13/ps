#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v1, v2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v1.push_back(num);
        v2.push_back(num);
    }

    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    
    for (int i = 0; i < n; i++) cout << lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin() << " ";
    cout << "\n";

    return 0;
}