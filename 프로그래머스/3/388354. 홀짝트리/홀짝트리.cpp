#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool visited[1000001];
vector<int> adj[1000001];

int check(int num, int size, int cur) {
    if (num % 2 == size % 2) {
        if (cur == 2) return -1;
        return 1;
    }
    else {
        if (cur == 1) return -1;
        return 2;
    }
}

int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cur = check(start, adj[start].size(), 0);
    
    while (!q.empty()) {
        int next = q.front();
        q.pop();
        
        for (int i : adj[next]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                cur = check(i, adj[i].size() - 1, cur);
                if (cur == -1) return -1;
            }
        }
    }
    
    return cur;
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer = {0, 0};
    
    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    for (int i : nodes) {
        int idx = bfs(i);
        if (idx != -1) answer[idx - 1]++;
        memset(visited, false, sizeof(visited));
    }
    
    return answer;
}