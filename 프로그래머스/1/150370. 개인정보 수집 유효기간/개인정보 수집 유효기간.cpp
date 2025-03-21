#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

map<char, int> m;
vector<int> v;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int year = stoi(today.substr(0, 4));
    int month = stoi(today.substr(5, 2));
    int day = stoi(today.substr(8, 2));
    int total = (year - 1) * 12 * 28 + (month - 1) * 28 + day;
    
    for (string str : terms) {
        stringstream ss(str);
        char c;
        int month;
        ss >> c >> month;
        m[c] = month;
    }
    
    for (string s : privacies) {
        int year = stoi(s.substr(0, 4));
        int month = stoi(s.substr(5, 2));
        int day = stoi(s.substr(8, 2));
        char c = s.back();
        
        int tmp = (year - 1) * 12 * 28 + (month - 1) * 28 + day + (m[c] * 28 - 1);
        v.push_back(tmp);
    }
    
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < total) answer.push_back(i + 1);
    }
    
    return answer;
}