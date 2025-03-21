#include <string>
#include <vector>
#include <sstream>

using namespace std;

string cell[2501];
int parent[2501];

int position(int r, int c) {
    return (r - 1) * 50 + c;
}

int find(int a) {
    if (a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a != b) {
        string val1 = cell[a], val2 = cell[b];
        if (val1 == "EMPTY" && val2 != "EMPTY") parent[a] = b;
        else parent[b] = a;
    }
}

void unmerge(int a) {
    int p = find(a);
    string val = cell[p];
    
    for (int i = 1; i <= 2500; i++) {
        if (find(i) == p) {
            parent[i] = i;
            cell[i] = "EMPTY";
        }
    }
    
    cell[a] = val;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for (int i = 1; i <= 2500; i++) {
        parent[i] = i;
        cell[i] = "EMPTY";
    }
    
    for (string cmd : commands) {
        vector<string> v;
        stringstream ss(cmd);
        string s;
        while (ss >> s) v.push_back(s);
        
        if (v[0] == "UPDATE") {
            if (v.size() == 4) {
                int a = position(stoi(v[1]), stoi(v[2]));
                //int p = find(a);
                int p = parent[a];
                cell[p] = v[3];
            }
            else {
                for (int i = 1; i <= 2500; i++) {
                    //int p = find(i);
                    if (cell[i] == v[1]) cell[i] = v[2];
                }
            }
        }
        else if (v[0] == "MERGE") {
            int a = position(stoi(v[1]), stoi(v[2])), b = position(stoi(v[3]), stoi(v[4]));
            //merge(a, b);
            a = parent[a];
            b = parent[b];
            if (a != b) {
                for (int i = 1; i <= 2500; i++) {
                    if (parent[i] == b) parent[i] = a;
                }
                string v1 = cell[a], v2 = cell[b];
                if (v1 == "EMPTY" && v2 != "EMPTY") cell[a] = cell[b];
                else cell[b] = cell[a];
            }
        }
        else if (v[0] == "UNMERGE") {
            int a = position(stoi(v[1]), stoi(v[2]));
            //unmerge(a);
            int p = parent[a];
            string val = cell[p];
            for (int i = 1; i <= 2500; i++) {
                if (parent[i] == p) {
                    parent[i] = i;
                    cell[i] = "EMPTY";
                }
            }
            cell[a] = val;
        }
        else {
            int a = position(stoi(v[1]), stoi(v[2]));
            int p = find(a);
            answer.push_back(cell[p]);
        }
    }
    
    return answer;
}