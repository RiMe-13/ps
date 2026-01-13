#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> c = {"c=","c-","dz=","d-","lj","nj","s=","z="};
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    for (string i : c) {
        while (true) {
            int idx = s.find(i);
            if (idx == string::npos) break;
            s.replace(idx, i.length(), "#");
        }
    }

    cout << s.length() << "\n";

    return 0;
}