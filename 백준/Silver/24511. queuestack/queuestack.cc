#include <iostream>
#include <deque>

using namespace std;

int n, m;
bool flag[100001];
deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> flag[i];
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (!flag[i]) dq.push_back(tmp);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        dq.push_front(tmp);
        cout << dq.back() << " ";
        dq.pop_back();
    }
    cout << "\n";

    return 0;
}