#include <iostream>
#include <string>

using namespace std;

string name, grade;
double credit, sum, tmp, res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 20; i++) {
        cin >> name >> credit >> grade;
        if (grade == "P") continue;

        sum += credit;
        if (grade == "F") continue;

        if (grade[0] == 'A') tmp = 4;
        else if (grade[0] == 'B') tmp = 3;
        else if (grade[0] == 'C') tmp = 2;
        else tmp = 1;

        if (grade[1] == '+') tmp += 0.5;

        res += (credit * tmp);
    }

    cout << res / sum << "\n";

    return 0;
}