#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            if (pq.empty()) cout << "0\n";
            else {
                pii c = pq.top();
                pq.pop();
                cout << c.second << "\n";
            }
        }
        else pq.push({abs(x), x});
    }

    return 0;
}