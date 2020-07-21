#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

const double INF = 1e15, EPS = 1e-7;

enum PointInfo {START, END};

struct Point {
    double x, y, r;
    PointInfo pInfo;

    Point():
        x(0),
        y(0),
        pInfo(START) {}

    ~Point() {}

    bool operator< (const Point &v) const {
        return
            (x < v.x)
            ||
            (x == v.x && y < v.y);
    }
};

int n;
vector<Point> a;

void readInput() {
    scanf("%d ", &n);
    a.clear();
    a.resize(2 * n);
    for(int i = 0;i < n;i++) {
        double r;
        scanf("%lf %lf %lf %lf %lf ", 
            &a[i].x, 
            &a[i].y, 
            &a[i + n].x, 
            &a[i + n].y, 
            &r);
        
        a[i].r = a[i + n].r = r;
        if(a[i].x < a[i + n].x) {
            a[i].pInfo = START;
            a[i + n].pInfo = END;
        }
        else {
            a[i].pInfo = END;
            a[i + n].pInfo = START;
        }
    }

    n *= 2;
}

void solve() {

    if(n == 0) {
        printf("1\n");
        printf("-inf +inf 1.000\n");
        return;
    }

    sort(a.begin(), a.end());

    double val = 1.0;
    double prev = -INF;

    printf("%d\n", n + 1);
    for(int i = 0;i < n;i++) {
        if(fabs(prev + INF) < EPS)
            printf("-inf ");
        else
            printf("%0.3lf ", prev);

        printf("%0.3lf %0.3lf\n", a[i].x, val);
        prev = a[i].x;

        if(a[i].pInfo == START)
            val *= a[i].r;
        else
            val /= a[i].r;
    }
    printf("%0.3lf +inf 1.000\n", prev);
}

int main() {
    int t;
    scanf("%d ", &t);
    for(int i = 0;i < t;i++) {
        if(i)
            printf("\n");
        readInput();
        solve();
    }
    return 0;
}