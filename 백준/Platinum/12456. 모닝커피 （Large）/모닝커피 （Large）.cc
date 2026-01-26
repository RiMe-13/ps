#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct coffee {
    long long c, d;
    int s;
};

struct d_cmp {
    bool operator()(const coffee& a, const coffee& b) {
        if (a.d != b.d) return a.d < b.d;
        else if (a.s != b.s) return a.s < b.s;
        return a.c > b.c;
    }
};

struct s_cmp {
    bool operator() (const coffee& a, const coffee& b) {
        if (a.s != b.s) return a.s < b.s;
        else if (a.c != b.c) return a.c < b.c;
        return a.d < b.d;
    }
};

int T, n;
long long k, cur, total;
priority_queue<coffee, vector<coffee>, d_cmp> d_pq;
priority_queue<coffee, vector<coffee>, s_cmp> s_pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        d_pq = {};
        s_pq = {};
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            long long c, d;
            int s;
            cin >> c >> d >> s;
            d_pq.push({c, d, s});
        }
        d_pq.push({0, 0, 0});

        total = 0;
        cur = d_pq.top().d;

        long long p = 0;
        while (!d_pq.empty() && cur) {
            coffee tmp = d_pq.top();
            d_pq.pop();

            p = cur - tmp.d;
            cur = tmp.d;

            while (!s_pq.empty()) {
                coffee cur_c = s_pq.top();
                s_pq.pop();

                if (p > cur_c.c) {
                    total += cur_c.s * cur_c.c;
                    p -= cur_c.c;
                }
                else {
                    total += cur_c.s * p;
                    cur_c.c -= p;
                    p = 0;

                    if (cur_c.c) s_pq.push(cur_c);
                }

                if (s_pq.empty() || p == 0) break;
            }

            s_pq.push(tmp);

            while (!d_pq.empty()) {
                tmp = d_pq.top();
                if (tmp.d == cur) {
                    d_pq.pop();
                    s_pq.push(tmp);
                }
                else break;
            }
        }

        cout << "Case #" << tc << ": " << total << "\n";
    }

    return 0;
}