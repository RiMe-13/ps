#include <iostream>

using namespace std;

struct Line {
    int x1, x2, y1, y2;
};

int n, g_cnt, max_val;
Line line[3001];
int parent[3001];
int cnt[3001];

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    a = find(a), b = find(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    long long tmp = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);

    if (tmp > 0) return 1;
    else if (tmp == 0) return 0;
    else return -1;
}

bool isCross(Line l1, Line l2) {
    int x1 = l1.x1; int y1 = l1.y1; int x2 = l1.x2; int y2 = l1.y2;
	int x3 = l2.x1; int y3 = l2.y1; int x4 = l2.x2; int y4 = l2.y2;

	if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) <= 0 &&
		ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) <= 0) {
		if ((x1 > x3 && x1 > x4 && x2 > x3 && x2 > x4) ||
			(x3 > x1 && x3 > x2 && x4 > x1 && x4 > x2)) return false;
		else if ((y1 > y3 && y1 > y4 && y2 > y3 && y2 > y4) ||
			(y3 > y1 && y3 > y2 && y4 > y1 && y4 > y2)) return false;
		else return true;
	}

	return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> line[i].x1 >> line[i].y1 >> line[i].x2 >> line[i].y2;
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (isCross(line[i], line[j])) Union(i, j);
        }
    }

    for (int i = 1; i <= n; i++) cnt[find(i)]++;

    for (int i = 1; i <= n; i++) {
        if (cnt[i]) g_cnt++;
        max_val = max(max_val, cnt[i]);
    }
    
    cout << g_cnt << "\n";
    cout << max_val << "\n";

    return 0;
}