#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<pii> meeting;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        meeting.push_back({e, s});
    }
    sort(meeting.begin(), meeting.end());
    int t = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (t <= meeting[i].second) {
            cnt++;
            t = meeting[i].first;
        }
    }
    cout << cnt << "\n";

    return 0;
}