#include<iostream>
#include<cmath>

using namespace std;

const double EPS = 1e-7;

struct Point {
    double x, y, z;

    Point():
        x(0),
        y(0),
        z(0) {}

    ~Point() {}
};

inline double sq(double u) {return u * u;}

inline double dist(const Point &u, const Point &v) {
    return sqrt(sq(u.x - v.x) + sq(u.y - v.y) + sq(u.z - v.z));
}

const int N = 5005;
int n;
Point a[N];
int ans[10];

void readInput() {

    n = 0;
    while(cin >> a[n].x >> a[n].y >> a[n].z) {
        if(fabs(a[n].x) < EPS && fabs(a[n].y) < EPS && fabs(a[n].z) < EPS)
            break;
        n ++;
    }
}

void solve() {
    for(int i = 0;i < 10;i++)
        ans[i] = 0;

    for(int i = 0;i < n;i++) {

        double minDist = -1;
        for(int j = 0;j < n;j++) {
            if(i == j)
                continue;

            double d = dist(a[i], a[j]);

            if(minDist < 0 || d < minDist - EPS)
                minDist = d;
        }

        if(minDist == -1 || minDist >= 10)
            continue;

        ans[static_cast<int>(minDist)] ++;
    }

    for(int i = 0;i < 10;i++)
        printf("%4d", ans[i]);
    printf("\n");
}

int main() {

    readInput();
    solve();

    return 0;
}