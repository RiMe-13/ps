#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 전역 변수 선언
int n, m, q;
int a[202020];
int in[202020];
int ltor[202020];

vector<int> l, r, idx;
vector<pair<int, int>> range_vec; // range는 C++20 등에서 키워드 충돌 가능성이 있어 이름 변경
priority_queue<int> ans;
priority_queue<int> del;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    // 1. 입력부 (f() -> cin 변경)
    cin >> n >> m >> q;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    l.resize(m); 
    r.resize(m);
    
    for(int i = 0; i < m; i++) cin >> l[i];
    for(int i = 0; i < m; i++) cin >> r[i];

    // 2. 로직 처리
    sort(l.begin(), l.end()); 
    sort(r.begin(), r.end());
    
    for(int i = 0; i < m; i++) {
        ltor[l[i]] = max(ltor[l[i]], r[i]);
        
        // 불가능한 구간 체크
        if(l[i] > r[i]) {
            for(int j = 0; j < q; j++) {
                cout << "1000000000\n";
            }
            return 0;
        }
    }
    
    // 구간 병합 (Merge Intervals)
    for(int i = 1; i <= n; i++) {
        if(ltor[i]) idx.push_back(i);
    }
    
    for(int i = 0, j; i < idx.size(); i = j + 1) {
        j = i;
        while(j + 1 < idx.size() && idx[j + 1] <= ltor[idx[j]]) {
            j++;
        }
        range_vec.push_back({idx[i], ltor[idx[j]]});
    }
    
    // 범위 내 요소 마킹
    for(auto &[left, right] : range_vec) {
        for(int i = left; i <= right; i++) {
            in[i] = 1;
        }
    }
    
    // 초기 힙 구성
    for(int i = 1; i <= n; i++) {
        if(in[i]) ans.push(a[i]);
    }
    
    // 3. 쿼리 처리
    while(q--) {
        int x, y;
        cin >> x >> y;
        
        // 범위 밖 -> 안, 안 -> 밖 이동 처리 (Lazy Deletion 준비)
        if(in[x] && in[y] == 0) {
            del.push(a[x]);
            ans.push(a[y]);
        }
        if(in[x] == 0 && in[y]) {
            del.push(a[y]);
            ans.push(a[x]);
        }
        
        swap(a[x], a[y]);
        
        // 삭제된 원소가 top에 있으면 제거 (Lazy Delete 적용)
        while(!ans.empty() && !del.empty() && ans.top() == del.top()) {
            ans.pop();
            del.pop();
        }
        
        cout << ans.top() << "\n";
    }
    
    return 0;
}