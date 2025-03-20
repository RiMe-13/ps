#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m; // 친구 리스트와 해당 인덱스를 저장
int gift[51][51]; // 주고받은 선물
int n[51]; // 선물 지수

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    for (int i = 0; i < friends.size(); i++) {
        string name = friends[i];
        m[name] = i;
    }
    
    for (string s : gifts) {
        int sp = s.find(' ');
        string fr = s.substr(0, sp);
        string to = s.substr(sp + 1);
        
        int fr_idx = m[fr];
        int to_idx = m[to];
        gift[fr_idx][to_idx]++;
        n[fr_idx]++;
        n[to_idx]--;
    }
    
    for (int i = 0; i < friends.size(); i++) {
        int tmp = 0;
        for (int j = 0; j < friends.size(); j++) {
            if (i == j) continue;
            if (gift[i][j] > gift[j][i]) tmp++;
            if (gift[i][j] == gift[j][i] && n[i] > n[j]) tmp++;
        }
        answer = max(answer, tmp);
    }
    
    return answer;
}