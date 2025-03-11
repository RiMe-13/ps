#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m;
int a, b, c;
int arr[1001];
vector<tuple<int, int, int>> edge;

int find(int a) {
	if (arr[a] == a) return a;
	else return arr[a] = find(arr[a]);
}

void u(int a, int b) {
	int aRoot = find(a);
	int bRoot = find(b);
	arr[aRoot] = bRoot;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i < n; i++) arr[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge.push_back(make_tuple(c, a, b));
	}
	sort(edge.begin(), edge.end());
	
	int result = 0;
	for (int i = 0; i < m; i++) {
		int v1 = get<1>(edge[i]);
		int v2 = get<2>(edge[i]);
		int w = get<0>(edge[i]);
		
		int p1 = find(v1);
		int p2 = find(v2);
		if (p1 != p2) {
			u(p1, p2);
			result += w;
		}
	} 
	
	cout << result << "\n";
	
	return 0;
}