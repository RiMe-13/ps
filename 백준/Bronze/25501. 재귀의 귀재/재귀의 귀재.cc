#include <iostream>
#include <string>

using namespace std;

int n, cnt;

int recursion(string& s, int l, int r){
    cnt++;

    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(string& s){
    cnt = 0;
    return recursion(s, 0, s.length()- 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << isPalindrome(s) << " " << cnt << "\n";
    }

    return 0;
}