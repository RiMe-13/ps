#include <iostream>

using namespace std;

char l[26];
char r[26];

void preorder(int i) {
	if (i == '.' - 'A') return;
	
	cout << (char)('A' + i);
	preorder(l[i] - 'A');
	preorder(r[i] - 'A');
}

void inorder(int i) {
	if (i == '.' - 'A') return;
	
	inorder(l[i] - 'A');
	cout << (char)('A' + i);
	inorder(r[i] - 'A');
}

void postorder(int i) {
	if (i == '.' - 'A') return;
	
	postorder(l[i] - 'A');
	postorder(r[i] - 'A');
	cout << (char)('A' + i);
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		char tmp;
		cin >> tmp;
		cin >> l[tmp - 'A'] >> r[tmp - 'A'];
	}
	
	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);

	return 0;
}