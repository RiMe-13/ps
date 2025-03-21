#include <iostream>
#include <vector>

using namespace std;

int n;
int a[1000001];
vector<int> ans;

int binarySearch(int x) {
    int left = 0, right = ans.size() - 1;
    
    while (left < right) {
        int mid = (left + right) / 2;

        if (ans[mid] >= x) right = mid;
        else left = mid + 1;
    }

    return right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ans.push_back(a[0]);

    for (int i = 1; i < n; i++) {
        if (a[i] > ans.back()) ans.push_back(a[i]);
        else {
            int idx = binarySearch(a[i]);
            ans[idx] = a[i];
        }
    }
    cout << ans.size() << "\n";

    return 0;
}