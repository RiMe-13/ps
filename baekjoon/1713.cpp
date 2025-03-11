#include <iostream>
#include <map>

using namespace std;

int main() {
	int n, rec_num;
	map<int, pair<int, int>> frame;

	cin >> n;
	cin >> rec_num;
	for (int i = 0; i < rec_num; i++) {
		int tmp;
		cin >> tmp;

		if (frame.find(tmp) == frame.end()) {
			if (frame.size() < n) {
				frame[tmp].first = 1;
				frame[tmp].second = i;
			}
			else {
				pair<int, int> min;
				int key = frame.begin()->first;
				min = frame.begin()->second;

				for (auto i : frame) {
					if (i.second < min) {
						key = i.first;
						min = i.second;
					}
				}
				frame.erase(key);
				frame[tmp] = { 1, i };
			}
		}
		else {
			frame[tmp].first++;
		}

	}

	for (auto i : frame) {
		cout << i.first << " ";
	}
	
	return 0;
}