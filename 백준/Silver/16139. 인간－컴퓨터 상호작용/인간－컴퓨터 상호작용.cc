#include <iostream>

using namespace std;

int q;
string s;
int sum[26][200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    sum[s[0] - 'a'][0] = 1;
    for (int i = 1; i < s.length(); i++) {
        for (int j = 0; j < 26; j++) sum[j][i] = sum[j][i - 1];
        sum[s[i] - 'a'][i]++;
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        
        if (l == 0) cout <<  sum[c - 'a'][r] << "\n";
        else cout << sum[c - 'a'][r] - sum[c - 'a'][l - 1] << "\n";
    }

    return 0;
}