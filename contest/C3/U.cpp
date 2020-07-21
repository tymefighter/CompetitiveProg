#include<iostream>
#include<cmath>

using namespace std;

struct Point {
    double x, y;

    Point(double x_, double y_):
        x(x_),
        y(y_) {}

    Point():
        x(0),
        y(0) {}

    ~Point() {}
};

double dist(const Point &u, const Point &v) {
    return hypot(u.x - v.x, u.y - v.y);
}

struct Circle {
    Point center;
    double r;

    Circle():
        center(Point()),
        r(0) {}

    Circle(const Point &center_, double r_):
        center(center_),
        r(r_) {}

    ~Circle() {} 

    bool isInsideOrOn(const Point &p) {
        return dist(p, center) <= r;
    }
};

int n;
long long a;
Circle c[4];

bool isInside(const Point &p) {
    for(int i = 0;i < 4;i++) {
        if(!c[i].isInsideOrOn(p))
            return false;
    }
    return true;
}

void solve() {
    double r = static_cast<double>(a);
    c[0] = Circle(Point(0, 0), r);
    c[1] = Circle(Point(r, 0), r);
    c[2] = Circle(Point(0, r), r);
    c[3] = Circle(Point(r, r), r);

    int numInside = 0;
    for(int i = 0;i < n;i++) {
        double x, y;
        cin >> x >> y;
        numInside += (isInside(Point(x, y)) ? 1 : 0);
    }

    double ans = numInside / static_cast<double>(n);
    ans *= a * a;
    printf("%0.5lf\n", ans);
}

int main() {

    while(cin >> n >> a) {
        if(!(n | a))
            break;
        solve();
    }
    return 0;
}