#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> n;
        if (n == -1) break;

        v.clear();
        int sum = 0;
        
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                sum += i;
                v.push_back(i);
            }
        }

        if (sum == n) {
            cout << n << " = ";
            for (int i = 0; i < v.size() - 1; i++) cout << v[i] << " + ";
            cout << v[v.size() - 1] << "\n";
        }
        else cout << n << " is NOT perfect.\n";
    }

    return 0;
}