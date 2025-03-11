#include <iostream>

using namespace std;

int heap[260000];
int heap_sz;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			if (heap_sz == 0) {
				cout << 0 << "\n";
				continue;
			}
			int out = heap[1];
			heap[1] = heap[heap_sz--];
			int node = 1;
			while (node <= heap_sz) {
				int l = node * 2;
				int r = node * 2 + 1;
				if (l <= heap_sz && heap[l] > heap[node] && (r > heap_sz || heap[l] >= heap[r])) {
					swap(heap[node], heap[l]);
					node = l;
				}
				else if (r <= heap_sz && heap[r] > heap[node] && heap[r] > heap[l]) {
					swap(heap[node], heap[r]);
					node = r;
				}
				else break;
			}
			cout << out << "\n";
		}
		else {
			heap[++heap_sz] = tmp;
			int node = heap_sz;
			while (node != 1 && heap[node] > heap[node / 2]) {
				swap(heap[node], heap[node / 2]);
				node /= 2;
			}
		}
	}
	
	return 0;
}