#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9;
int n, w;
pii c[1002]; // 사건의 좌표
int dp[1001][1001]; // dp[i][j] : 1번 경찰차 위치가 i번 사건, 2번 경찰차가 j번 사건을 마지막으로 해결했을 때의 최소 비용
int cache[1001][1001]; // i와 j의 차가 1일 때 어디로 갔는지 표시..
int police[1001]; // i번째 사건을 해결한 경찰차 번호

int dist(int a, int b) {
	return abs(c[a].first - c[b].first) + abs(c[a].second - c[b].second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> w;
	for (int i = 1; i <= w; i++) {
		int x, y;
		cin >> x >> y;
		c[i] = { x, y };
	}

	dp[0][0] = INF;
	dp[0][1] = n + n - c[1].first - c[1].second;
	dp[1][0] = c[1].first + c[1].second - 2;
	for (int i = 2; i <= w; i++) dp[0][i] = dp[0][i - 1] + dist(i - 1, i);
	for (int i = 2; i <= w; i++) dp[i][0] = dp[i - 1][0] + dist(i - 1, i);

	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= w; j++) {
			if (i == j) dp[i][j] = INF;
			else if (i < j) {
				if (i + 1 == j) {
					int min_val = dp[i][0] + (n + n - c[j].first - c[j].second);
					for (int k = 1; k <= i; k++) {
						if (min_val > dp[i][k] + dist(k, j)) {
							min_val = dp[i][k] + dist(k, j);
							cache[i][j] = k;
						}
					}
					dp[i][j] = min_val;
				}
				else dp[i][j] = dp[i][j - 1] + dist(j - 1, j);
			}
			else {
				if (j + 1 == i) {
					int min_val = dp[0][j] + (c[i].first + c[i].second - 2);
					for (int k = 1; k <= j; k++) {
						if (min_val > dp[k][j] + dist(k, i)) {
							min_val = dp[k][j] + dist(k, i);
							cache[i][j] = k;
						}
					}
					dp[i][j] = min_val;
				}
				else dp[i][j] = dp[i - 1][j] + dist(i - 1, i);
			}
		}
	}
	// 최저 비용은 min(dp[n][i], dp[i][n])을 해서 구하면 된다. 그러면 최종 결과는 어떻게 구하나?
	int a = w, b = w;
	int result = INF;
	for (int i = 0; i <= w; i++) {
		if (result > dp[w][i]) {
			result = dp[w][i];
			a = w;
			b = i;
		}
		if (result > dp[i][w]) {
			result = dp[i][w];
			a = i;
			b = w;
		}
	}
	//cout << "Debug: " << a << " " << b << "\n";
	cout << dp[a][b] << "\n";

	int k = w;
	// w번째 사건부터 누가 처리했는지 검사
	// 만약 a > b라면 n번째 사건은 1이 처리, 아니면 2가 처리
	// 1 차이가 아니라면 쭉 감소시킨다!
	// 1 차이라면, cache 배열을 통해 k를 가져와서 a를 k로 만든다!
	// a < b일 때도 똑같이
	// 언제까지? k > 0일 동안!
	while (k > 0) {
		if (a > b) {
			while (a != b + 1) {
				police[k--] = 1;
				a--;
			}
			a = cache[a][b];
			police[k--] = 1;
		}
		else {
			while (b != a + 1) {
				police[k--] = 2;
				b--;
			}
			b = cache[a][b];
			police[k--] = 2;
		}
	}

	for (int i = 1; i <= w; i++) cout << police[i] << "\n";

	return 0;
}