#include <iostream>
#include <stack>

using namespace std;

int n;
int a[1000001], f[1000001], ngf[1000001];
stack<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        while (!s.empty() && f[a[s.top()]] < f[a[i]]) {
            ngf[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        ngf[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++) cout << ngf[i] << " ";
    cout << "\n";

    return 0;
}