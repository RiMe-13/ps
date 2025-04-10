#include <iostream>
#include <vector>

using namespace std;

int q, n;
vector<int> st;
vector<vector<int>> mountain;

int binarySearch(int h) {
    int idx = mountain.size();
    if (idx == 0) return 0;
    int left = 0, right = idx - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        int min_val = mountain[mid].back();
        if (min_val < h) left = mid + 1;
        else {
            idx = mid;
            right = mid - 1;
        }
    }

    return idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> q;
    for (int i = 0; i < q; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 100) {
            cin >> n;
            for (int i = 0; i < n; i++) {
                int h;
                cin >> h;
                int idx = binarySearch(h);
                st.push_back(idx);

                if (idx == mountain.size()) mountain.push_back(vector<int>());
                mountain[idx].push_back(h);
            }
        }
        else if (cmd == 200) {
            int h;
            cin >> h;
            int idx = binarySearch(h);
            st.push_back(idx);
            if (idx == mountain.size()) mountain.push_back(vector<int>());
            mountain[idx].push_back(h);
            n++;
        }
        else if (cmd == 300) {
            int last = st.back();
            st.pop_back();
            mountain[last].pop_back();
            if (mountain[last].empty()) mountain.erase(mountain.begin() + last);
            n--;
        }
        else {
            int m_idx;
            cin >> m_idx;
            m_idx--;
            long long cnt = ((long long) (st[m_idx]) + mountain.size()) * 1000000LL;
            cnt += mountain.back().front();
            cout << cnt << "\n";
        }
    }

    return 0;
}