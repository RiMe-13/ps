#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int w, int num) {
    vector<vector<int>> box;
    int h = n / w;
    if (n % w) h++;
    
    bool even = true;
    int cnt = 1;
    int x = 0, y = 0;
    
    for (int i = 0; i < h; i++) {
        vector<int> v;
        for (int j = 0; j < w; j++) {
            if (cnt > n) v.push_back(0);
            else v.push_back(cnt);
            
            if (cnt == num) {
                x = i;
                y = even ? j : w - j - 1;
            }
            cnt++;
        }
        
        if (!even) reverse(v.begin(), v.end());
        box.push_back(v);
        even = !even;
    }
    
    int answer = h - x;
    if (box[h - 1][y] == 0) answer--;
    
    return answer;
}