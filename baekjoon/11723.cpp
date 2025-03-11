#include <iostream>
#include <set>

using namespace std;

int arr[21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    string cmd;
    cin >> m;
    for (int t = 0; t < m; t++) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> n;
            arr[n] = 1;
        }
        else if (cmd == "remove") {
            cin >> n;
            arr[n] = 0;
        }
        else if (cmd == "check") {
            cin >> n;
            if (arr[n] == 1) cout << "1\n";
            else cout << "0\n";
        }
        else if (cmd == "toggle") {
            cin >> n;
            if (arr[n] == 1) arr[n] = 0;
            else arr[n] = 1;
        }
        else if (cmd == "all") {
            for (int i = 1; i <= 20; i++) arr[i] = 1;
        }
        else for (int i = 1; i <= 20; i++) arr[i] = 0;
    }

    return 0;
}