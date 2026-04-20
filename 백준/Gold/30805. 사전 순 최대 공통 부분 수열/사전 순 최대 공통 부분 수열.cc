#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, tmp;
vector<int> a, b, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        b.push_back(tmp);
    }

    bool flag = true;
    int max_a, a_idx, max_b, b_idx;

    while (true) {
        while (true) {
            if (a.empty() || b.empty()) {
                flag = false;
                break;
            }

            max_a = *max_element(a.begin(), a.end());
            a_idx = max_element(a.begin(), a.end()) - a.begin();
            max_b = *max_element(b.begin(), b.end());
            b_idx = max_element(b.begin(), b.end()) - b.begin();

            if (max_a == max_b) break;
            else if (max_a > max_b) a.erase(a.begin() + a_idx);
            else b.erase(b.begin() + b_idx);
        }
        if (!flag) break;

        ans.push_back(max_a);

        int num = 0;
        for (int i = a_idx + 1; i < a.size(); i++) {
            a[num] = a[i];
            num++;
        }
        for (int i = 0; i < a_idx + 1; i++) a.pop_back();

        num = 0;
        for (int i = b_idx + 1; i < b.size(); i++) {
            b[num] = b[i];
            num++;
        }
        for (int i = 0; i < b_idx + 1; i++) b.pop_back();
    }

    if (!ans.empty()) {
        cout << ans.size() << "\n";
        for (int i : ans) cout << i << " ";
        cout << "\n";
    }
    else cout << "0\n";

    return 0;
}