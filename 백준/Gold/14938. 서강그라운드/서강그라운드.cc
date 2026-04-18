#include<iostream>
#include<algorithm>

using namespace std;

int ans, cnt;
int n, m, r;
const int INF = 1e9;
int local[101];
int dist[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) dist[i][j] = INF;
		}
	}

	for (int i = 1; i <= n; i++) cin >> local[i];
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		dist[a][b] = l;
		dist[b][a] = l;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cnt = local[i];
		for (int j = 0; j <= n; j++) {
			if (i != j && dist[i][j] <= m) cnt += local[j];
		}
		ans = max(ans, cnt);
	}
		
	cout << ans << "\n";

	return 0;
}