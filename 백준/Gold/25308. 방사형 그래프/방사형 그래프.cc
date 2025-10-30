#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int ans = 0;
ll arr[8];
bool visited[8];
vector<ll> v;

bool check(ll& x, ll& y, ll& z) {
	return (x + z) * (x + z) * y * y >= 2 * x * x * z * z;
}

void solve(int cnt) {
	if (cnt == 8) {
		if (check(v[0], v[1], v[2]) &&
			check(v[1], v[2], v[3]) &&
			check(v[2], v[3], v[4]) &&
			check(v[3], v[4], v[5]) &&
			check(v[4], v[5], v[6]) &&
			check(v[5], v[6], v[7]) &&
			check(v[6], v[7], v[0]) &&
			check(v[7], v[0], v[1])) 
            ans++;
		return;
	}
	for (int i = 0; i < 8; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
        v.push_back(arr[i]);
		solve(cnt + 1);
		v.pop_back();
		visited[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 8; i++) cin >> arr[i];

	solve(0);

	cout << ans << "\n";
}