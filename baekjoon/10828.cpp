#include <iostream>
#include <string>

using namespace std;

int st[10003];
int top = 0;

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		if (cmd.compare("push") == 0) {
			int tmp;
			cin >> tmp;
			st[top++] = tmp;
		}
		else if (cmd.compare("pop") == 0) {
			if (top == 0) cout << -1 << endl;
			else cout << st[--top] << endl;
		}
		else if (cmd.compare("size") == 0) cout << top << endl;
		else if (cmd.compare("empty") == 0) {
			if (top == 0) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else {
			if (top == 0) cout << -1 << endl;
			else cout << st[top - 1] << endl;
		}
	}
	

	return 0;
}