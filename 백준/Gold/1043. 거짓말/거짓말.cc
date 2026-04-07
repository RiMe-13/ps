#include <iostream>
#include <vector>

using namespace std;

int n, m, p;
int parent[51];
vector<int> truth, party[51];

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    a = find(a), b = find(b);
    parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> p;
    for (int i = 0; i < p; i++) {
        int tmp;
        cin >> tmp;
        truth.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int tmp;
            cin >> tmp;
            party[i].push_back(tmp);
        }
    }
    int answer = m;

    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < party[i].size(); j++) Union(party[i][0], party[i][j]);
    }

    for (int i = 0; i < m; i++) {
        bool go = true;
        for (int j = 0; j < party[i].size(); j++) {
            if (!go) break;

            for (int k = 0; k < truth.size(); k++) {
                if (find(party[i][j]) == find(truth[k])) {
                    go = false;
                    break;
                }
            }
        }

        if (!go) answer--;
    }

    cout << answer << "\n";

    return 0;
}