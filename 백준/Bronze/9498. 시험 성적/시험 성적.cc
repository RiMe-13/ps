#include <iostream>

using namespace std;

int score;
char grade;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> score;
    if (score >= 90) grade = 'A';
    else if (score >= 80) grade = 'B';
    else if (score >= 70) grade = 'C';
    else if (score >= 60) grade = 'D';
    else grade = 'F';

    cout << grade << "\n";

    return 0;
}