#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool prime[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i <= 1000; i++) prime[i] = true;
    for (int i = 2; i <= sqrt(1000); i++) {
        if (!prime[i]) continue;

        for (int j = i * i; j <= 1000; j += i) prime[j] = false;
    }

    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (prime[tmp]) cnt++;
    }
    cout << cnt << "\n";

    return 0;
}