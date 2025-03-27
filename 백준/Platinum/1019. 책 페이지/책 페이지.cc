#include <iostream>
#include <cmath>

using namespace std;

int n;
long long cnt[10];

int last_nine(int num) {
    while (true) {
        if (num % 10 == 9) break;
        num--;
    }
    return num;
}

void count(int a, int b, int digit) {
    if (b < 10) {
        for (int i = a; i <= b; i++) cnt[i] += (long long) digit;
        return;
    }

    int tmp = last_nine(b);

    for (int i = tmp + 1; i <= b; i++) {
        string s = to_string(i);
        for (int j = 0; j < s.size(); j++) {
            int idx = s[j] - '0';
            cnt[idx] += (long long) digit;
        }
    }

    for (int i = 0; i < 10; i++) {
        cnt[i] += (long long) ((tmp / 10 - a / 10 + 1) * digit);
    }

    count(a / 10, tmp / 10, digit * 10);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    if (n < 10) {
        for (int i = 1; i <= n; i++) cnt[i]++;
    }
    else {
        int len = to_string(n).size();
        int a = (int)pow(10, len - 1);

        if (a > last_nine(n)) {
            for (int i = last_nine(n) + 1; i <= n; i++) {
                string s = to_string(i);
                for (int j = 0; j < s.size(); j++) {
                    int idx = s[j] - '0';
                    cnt[idx]++;
                }
            }
            a /= 10;
            count(a, last_nine(n), 1);
        }
        else count(a, n, 1);
        
        while (true) {
            if (a == 1) break;
            count(a / 10, a - 1, 1);
            a /= 10;
        }
    }

    for (int i = 0; i < 10; i++) cout << cnt[i] << " ";
    cout << "\n";

    return 0;
}