#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9;
int n, m, min_val = INF;
bool selected[14];
vector<pii> house, chicken, picked;

int dist(pii x, pii y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

void find_dist() {
    int res = 0;
    for (pii i : house) {
        int min_d = INF;
        for (pii j : picked) {
            min_d = min(min_d, dist(i, j));
        }
        res += min_d;
    }
    min_val = min(min_val, res);
}

void find_com(int x, int cnt) {
    if (m == cnt) find_dist();

    for (int i = x; i < chicken.size(); i++) {
        if (selected[i]) continue;

        selected[i] = true;
        picked.push_back(chicken[i]);
        find_com(i, cnt + 1);
        selected[i] = false;
        picked.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1) house.push_back({i, j});
            else if (tmp == 2) chicken.push_back({i, j});
        }
    }
    find_com(0, 0);
    cout << min_val << "\n";

    return 0;
}