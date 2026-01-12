#include <iostream>

using namespace std;

int cnt[26];
int max_val = -1, check = 0;
char res;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';

		if (++cnt[s[i] - 'A'] > max_val) { 
			max_val = cnt[s[i] - 'A'];
			res = s[i];
		}
	}

	for (int i = 0; i < 26; i++) {
		if (max_val == cnt[i]) check++;
	}

	if (check == 1) cout << res << "\n";
	else cout << "?\n";

    return 0;
}