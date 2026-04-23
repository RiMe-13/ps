#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
int score[1000001];
bool card[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        card[tmp] = true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = v[i] * 2; j < 1000001; j += v[i]) {
            if (card[j]) {
                score[v[i]]++;
                score[j]--;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << score[v[i]] << " ";
    cout << "\n";

    return 0;
}