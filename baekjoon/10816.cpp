#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> m;
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        m[tmp]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        cout << m[tmp]<< " ";
    }
    cout << "\n";

    return 0;
}