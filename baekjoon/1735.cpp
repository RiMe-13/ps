#include <iostream>
#include <numeric>

using namespace std;

int a, b, c, d;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	return (a * b) / gcd(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> a >> b;
	cin >> c >> d;
	
	long long res2 = lcm(b, d);
	long long res1 = a * (res2 / b) + c * (res2 / d);
	
	long long ans1 = res1 / gcd(res1, res2);
	long long ans2 = res2 / gcd(res1, res2);
	cout << ans1 << " " << ans2 << "\n";
	
	return 0;
}