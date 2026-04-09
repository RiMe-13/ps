#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
double avg[51];
bool flag;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> avg[i];
        avg[i] = avg[i] - floor(avg[i]);
        avg[i] = round(avg[i] * 1000.0) / 1000.0;
    }

    vector<double> cases(1001);
    for (int num = 1; num <= 1000; num++) {
        for (int score = 1; score <= num; score++) {
            cases[score] = floor((static_cast<double>(score) / num) * 1000) / 1000.0;
        }
        flag = true;
        for (int j = 0; j < n; j++) {
            if (find(cases.begin(), cases.end(), avg[j]) == cases.end()) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << num << "\n";
            break;
        }
    }

    return 0;
}