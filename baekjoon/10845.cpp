#include <iostream>

using namespace std;
int queue[10003];

int main() {
    int n;
    cin >> n;

    int front = 0, back = 0;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int num;
            cin >> num;
            queue[back++] = num;
        } else if (cmd == "pop") {
            if (front == back) cout << -1 << endl;
            else cout << queue[front++] << endl;
        } else if (cmd == "size") {
            cout << back - front << endl;
        } else if (cmd == "empty") {
            cout << (front == back) << endl;
        } else if (cmd == "front") {
            if (front == back) cout << -1 << endl;
            else cout << queue[front] << endl;
        } else if (cmd == "back") {
            if (front == back) cout << -1 << endl;
            else cout << queue[back - 1] << endl;
        }
    }

    return 0;
}