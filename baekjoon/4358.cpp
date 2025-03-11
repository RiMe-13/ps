#include <iostream>
#include <map>

using namespace std;

map<string, int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int size = 0;
	string s;
	while (getline(cin, s)) {
		if (m.find(s) != m.end()) {
			m[s]++;
		}
		else m[s] = 1;
		size++;
	}
	
	cout << fixed;
	cout.precision(4);
	
	for (auto i : m) {
		double out = (double) (i.second * 100) / (double) size;
		cout << i.first << " " << out << "\n";
	}
	
	return 0;
}