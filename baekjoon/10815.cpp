#include<iostream>
#include<algorithm>

using namespace std;

int a[500001];
int b[500001] = { 0, }; // 정답 저장 배열

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
    sort(a, a + n);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
        int target;
		cin >> target;
        int r = n - 1;
        int l = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] == target) {
                b[i] = 1;
                break;
            }
            if (a[m] > target) r = m - 1;
            else l = m + 1;
        }
	}
    for (int i = 0; i < m; i++) {
		cout << b[i] << ' ';
	}
	return 0;
}