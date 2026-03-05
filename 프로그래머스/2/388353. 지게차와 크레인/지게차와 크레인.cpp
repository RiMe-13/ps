#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n, m;
bool visited[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isin(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void car(char c, vector<string> &storage) {
    vector<pii> save;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (storage[i][j] == c) {
                if (i == 0 || j == 0 || i == (n - 1) || j == (m - 1)) save.push_back({i, j});
                else {
                    queue<pii> tmp;
                    memset(visited, false, sizeof(visited));
                    visited[i][j] = true;
                    
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k], ny = j + dy[k];
                        if (isin(nx, ny) && !visited[nx][ny] && storage[nx][ny] == ' ') {
                            tmp.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                    
                    while (!tmp.empty()) {
                        pii cur = tmp.front();
                        int x = cur.first, y = cur.second;
                        tmp.pop();
                        
                        if (x == 0 || y == 0 || x == (n - 1) || y == (m - 1)) {
                            save.push_back({i, j});
                            break;
                        }
                        
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k], ny = y + dy[k];
                            
                            if (isin(nx, ny) && !visited[nx][ny] && storage[nx][ny] == ' ') {
                                tmp.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    
    for (pii i : save) {
        storage[i.first][i.second] = ' ';
    }
}

void crain(char c, vector<string> &storage) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (storage[i][j] == c) storage[i][j] = ' ';
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    n = storage.size();
    m = storage[0].size();
    
    for (int i = 0; i < requests.size(); i++) {
        char c = requests[i][0];
        if (requests[i].size() == 1) car(c, storage);
        else crain(c, storage);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (storage[i][j] != ' ') answer++;
        }
    }
    
    return answer;
}