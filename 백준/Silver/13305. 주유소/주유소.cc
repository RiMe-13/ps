#include <iostream>

using namespace std;

int n;
int dist[100001];
int cost[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i < n; i++) cin >> dist[i];
    for (int i = 1; i <= n; i++) cin >> cost[i];

    int min_val = 2147483647;
    long long sum = 0;

    for (int i = 1; i < n; i++) {
        if (cost[i] < min_val) min_val = cost[i];
        sum += (long long) min_val * (long long) dist[i];
    }

    cout << sum << "\n";

    return 0;
}