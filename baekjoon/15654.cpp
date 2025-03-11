#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
int input[9];
bool visited[9];

void dfs(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[cnt] = input[i];
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    sort(input, input + n);
    dfs(0);

    return 0;
}