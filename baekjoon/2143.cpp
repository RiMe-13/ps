#include <iostream>
#include <algorithm>

using namespace std;

int t, n, m;
long long cnt;
int a[1001];
int b[1001];
int a_sum[1000001];
int b_sum[1000001];

void count() {
	int idxA = 0, idxB = 0;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = i; j < n; j++) {
			tmp += a[j];
			a_sum[idxA++] = tmp;
		}
	}
	for (int i = 0; i < m; i++) {
		int tmp = 0;
		for (int j = i; j < m; j++) {
			tmp += b[j];
			b_sum[idxB++] = tmp;
		}
	}
	
	sort(a_sum, a_sum + idxA);
	sort(b_sum, b_sum + idxB);
	
	int l = 0, r = idxB - 1;
	
	while (l < idxA && r >= 0) {
		if (a_sum[l] + b_sum[r] < t) l++;
		else if (a_sum[l] + b_sum[r] > t) r--;
		else {
			long long a_cnt = 0, b_cnt = 0;
			int a_val = a_sum[l], b_val = b_sum[r];
			while (a_sum[l] == a_val && l < idxA) {
				a_cnt++;
				l++;
			}
			while (b_sum[r] == b_val && r >= 0) {
				b_cnt++;
				r--;
			}
			cnt += (a_cnt * b_cnt);
		}
	}
}

int main() {
	cin >> t;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) a_sum[i] = a[i];
		else a_sum[i] = a_sum[i - 1] + a[i];
	}
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	
	count();

	cout << cnt << endl;

	return 0;
}