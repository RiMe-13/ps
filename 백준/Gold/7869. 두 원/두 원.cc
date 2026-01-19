#include <iostream>
#include <cmath>

using namespace std;



void swap(double &x, double &y)
{
	double tmp = x;
	x = y;
	y = tmp;
}

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double pi = 3.14159265358979;
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    cout << fixed;
    cout.precision(3);
    if (r1 < r2) {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }
    double d = dist(x1, y1, x2, y2);
    if (d >= r1 + r2) cout << "0.000\n";
    else if (d + r2 <= r1) cout << r2 * r2 * pi << "\n";
    else {
        double t1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
        double t2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));

        double s1 = (r1 * r1 * 2 * t1) / 2 - r1 * r1 * sin(2 * t1) / 2;
        double s2 = (r2 * r2 * 2 * t2) / 2 - r2 * r2 * sin(2 * t2) / 2;

        cout << s1 + s2 << "\n";
    }

    return 0;
}