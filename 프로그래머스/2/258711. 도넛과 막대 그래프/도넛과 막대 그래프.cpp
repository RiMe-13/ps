#include <string>
#include <vector>
#include <queue>

using namespace std;

int cnt_0, cnt_1, cnt_8;
int indegree[1000001];
int outdegree[1000001];
vector<int> adj[1000001];
queue<int> q;

void bfs(int n) {
    q.push(n);
    bool visited = false;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (cur == n && visited) {
            cnt_0++;
            return;
        }
        if (adj[cur].size() >= 2) {
            cnt_8++;
            return;
        }
        
        for (int v : adj[cur]) q.push(v);
        visited = true;
    }
    
    cnt_1++;
    return;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    for (int i = 0; i < edges.size(); i++) {
        indegree[edges[i][1]]++;
        outdegree[edges[i][0]]++;
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    for (int i = 1; i < 1000001; i++) {
        if (indegree[i] == 0 && outdegree[i] >= 2) answer.push_back(i);
    }
    
    for (int x : adj[answer[0]]) bfs(x);
    
    answer.push_back(cnt_0);
    answer.push_back(cnt_1);
    answer.push_back(cnt_8);
    
    return answer;
}