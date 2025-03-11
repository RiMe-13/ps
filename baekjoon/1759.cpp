#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
char arr[20];
char word[20];

// word의 i번째 문자를 arr의 x번째 문자부터 사용 가능
void backtrack(int i, int x) {
	if (i == l) {
		int a_cnt = 0;
		int b_cnt = 0;
		for (int j = 0; j < l; j++) {
			if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u') a_cnt++;
			else b_cnt++;
		}
		if (a_cnt >= 1 && b_cnt >= 2) cout << word << "\n";
		return;
	}
	else {
		for (int j = x; j < c; j++) {
			word[i] = arr[j];
			
			backtrack(i + 1, j + 1);
		}
	}
}

int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + c);
	backtrack(0, 0);

	return 0;
}