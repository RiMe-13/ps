#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int t, n;
string p, arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        deque<int> dq;
        string tmp = "";
        bool is_reverse = false, error = false;

        cin >> p;
        cin >> n;
        cin >> arr;

        for (int i = 1; i < arr.length(); i++) {
            if (arr[i] == ',' || arr[i] == ']') {
                if (tmp != "") {
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
            }
            else tmp += arr[i];
        }

        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') is_reverse = !is_reverse;
            else if (p[i] == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                else {
                    if (is_reverse) dq.pop_back();
                    else dq.pop_front();
                }
            }
        }

        if (error) cout << "error\n";
        else {
            if (is_reverse) reverse(dq.begin(), dq.end());

            cout << "[";
            for (int i = 0; i < dq.size(); i++) {
                if (i == dq.size() - 1) cout << dq[i];
                else cout << dq[i] << ",";
            }
            cout << "]\n";
        }
    }

    return 0;
}