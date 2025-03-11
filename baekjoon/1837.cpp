#include <iostream>
#include <string>

using namespace std;

string p;
long long k;
bool arr[1000000];

void check() {
    for (long long i = 2; i < k; i++) {
        if (arr[i] == false) {
            int res = 0;
            for (int j = 0; j < p.length(); j++) res = (res * 10 + p[j] - '0') % i;
            if (!res) {
                cout << "BAD " << i << "\n";
                return;
            }
        }
    }
    cout << "GOOD\n";
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin >> p >> k;

    for (int i = 2; i * i < k; i++) {
        if (arr[i] == false) {
            for (int j = i * i; j < k; j += i) arr[j] = true;
        }
    }

    check();

    return 0;
}