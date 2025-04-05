#include <iostream>
#include <queue>

using namespace std;

int t;
int m;
priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        pq1 = {};
        pq2 = {};
        cin >> m;
        cout << m / 2 + m % 2 << "\n";
        for (int i = 0; i < m; i++) {
            int tmp;
            cin >> tmp;
            if (pq1.size() > pq2.size()) pq2.push(tmp);
            else pq1.push(tmp);

            if (!pq2.empty() && pq1.top() > pq2.top()) {
                int v1 = pq1.top();
                pq1.pop();
                int v2 = pq2.top();
                pq2.pop();

                pq1.push(v2);
                pq2.push(v1);
            }
            
            if (i % 2 == 0) cout << pq1.top() << " ";
        }
        cout << "\n";
    }

    return 0;
}