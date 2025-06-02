#include <iostream>

using namespace std;

typedef pair<int, int> pii;

pii a, b, c;

int ccw(pii a, pii b, pii c) {
    int result = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
    
    if (result < 0) return -1;
    else if (result > 0) return 1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
    cout << ccw(a, b, c) << "\n";

    return 0;
}