#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void execute(int init, vector<string> input_arr) {
	long long tmp; // 계산 임시 결과, 범위 초과 확인용
	int top = 0;
	vector<int> stk;
	stk.push_back(init);

	for (auto i = input_arr.begin(); i != input_arr.end(); i++) {
		if (*i == "POP") {
			if (stk.empty()) {
				cout << "ERROR" << endl;
				return;
			}
			stk.pop_back();
			top--;
		}
		else if (*i == "INV") {
			if (stk.empty()) {
				cout << "ERROR" << endl;
				return;
			}
			stk[top] *= (-1);
		}
		else if (*i == "DUP") {
			stk.push_back(stk[top]);
			top++;
		}
		else if (*i == "SWP") {
			if (top < 1) {
				cout << "ERROR" << endl;
				return;
			}
			int temp;
			temp = stk[top];
			stk[top] = stk[top - 1];
			stk[top - 1] = temp;
		}
		else if (*i == "ADD") {
			if (top < 1) {
				cout << "ERROR" << endl;
				return;
			}
			tmp = (long long)stk[top] + (long long)stk[top - 1];
			if (tmp > 1000000000 || tmp < -1000000000) {
				cout << "ERROR" << endl;
				return;
			}
			stk.pop_back();
			stk.pop_back();
			stk.push_back(tmp);
			top--;
		}
		else if (*i == "SUB") {
			if (top < 1) {
				cout << "ERROR" << endl;
				return;
			}
			tmp = (long long)stk[top - 1] - (long long)stk[top];
			if (tmp > 1000000000 || tmp < -1000000000) {
				cout << "ERROR" << endl;
				return;
			}
			stk.pop_back();
			stk.pop_back();
			stk.push_back(tmp);
			top--;
		}
		else if (*i == "MUL") {
			if (top < 1) {
				cout << "ERROR" << endl;
				return;
			}
			tmp = (long long)stk[top] * (long long)stk[top - 1];
			if (tmp > 1000000000 || tmp < -1000000000) {
				cout << "ERROR" << endl;
				return;
			}
			stk.pop_back();
			stk.pop_back();
			stk.push_back(tmp);
			top--;
		}
		else if (*i == "DIV") {
			if (top < 1 || stk[top] == 0) {
				cout << "ERROR" << endl;
				return;
			}

			int minus = 0; // 마이너스 부호 수
			if (stk[top] < 0) {
				minus++;
				stk[top] *= (-1);
			}
			if (stk[top - 1] < 0) {
				minus++;
				stk[top - 1] *= (-1);
			}

			tmp = stk[top - 1] / stk[top];
			if (tmp > 1000000000 || tmp < -1000000000) {
				cout << "ERROR" << endl;
				return;
			}
			if (minus == 1) tmp *= (-1);
			stk.pop_back();
			stk.pop_back();
			stk.push_back(tmp);
			top--;
		}
		else if (*i == "MOD") {
			if (top < 1 || stk[top] == 0) {
				cout << "ERROR" << endl;
				return;
			}

			int minus = 0; // 마이너스 부호 수
			if (stk[top] < 0) {
				stk[top] *= (-1);
			}
			if (stk[top - 1] < 0) {
				minus++;
				stk[top - 1] *= (-1);
			}
			tmp = stk[top - 1] % stk[top];
			if (tmp > 1000000000 || tmp < -1000000000) {
				cout << "ERROR" << endl;
				return;
			}
			
			if (minus == 1) tmp *= (-1);
			stk.pop_back();
			stk.pop_back();
			stk.push_back(tmp);
			top--;
		}
		else {
			string str = *i;
			string substr;
			istringstream ss (str);
			vector<string> str_arr;
			
			while (getline(ss, substr, ' ')) {
				str_arr.push_back(substr);
			}
			int tmp = stoi(str_arr[1]);
			stk.push_back(tmp);
			top++;
		}
	}

	if (top == 0) {
		cout << stk[0] << endl;
	}
	else {
		cout << "ERROR" << endl;
	}
	return;
}

int main() {
	vector<string> input_arr;
	string input;

	while (true) {
		// 프로그램 부분
		while (true) {
			getline(cin, input);
			if (input.compare("END") == 0) {
				break;
			}
			else if (input.compare("QUIT") == 0) {
				return 0;
			}
			else if (input.compare("") == 0) {
				continue;
			}
			input_arr.push_back(input);
		}

		// 입력 영역 부분
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			execute(k, input_arr);
		}
		cout << endl;

		input_arr.clear();
	}

	return 0;
}