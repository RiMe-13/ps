#include <iostream>
#include <vector>

using namespace std;

int n;
int a[100001];
vector<int> ans;

void find(int target) {
    int s = 0, e = ans.size() - 1;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (ans[mid] < target) s = mid + 1;
        else e = mid - 1;
    }

    if (s >= ans.size()) ans.push_back(target);
    else ans[s] = target;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a[tmp] = i;
    }
    
    int tmp;
    cin >> tmp;
    ans.push_back(a[tmp]);
    for (int i = 1; i < n; i++) {
        cin >> tmp;
        find(a[tmp]);
    }
    cout << ans.size() << "\n";

    return 0;
}