#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<int, bool> um;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        int tmp;
        cin >> tmp;

        if (um[tmp] == true) um.erase(tmp);
        else um[tmp] = true;
    }

    cout << um.size() << "\n";

    return 0;
}