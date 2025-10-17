#include <iostream>

using namespace std;

const int MAX = 1000001;
int t, n;
bool prime[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < MAX; i++) prime[i] = true;
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < MAX; i++) {
        if (prime[i]) {
            for (int j = i * 2; j <= MAX; j += i) prime[j] = false;
        }
    }

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int cnt = 0;
        cin >> n;

        for (int i = 2; i <= n / 2; i++) {
            if (prime[i] && prime[n - i]) cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}