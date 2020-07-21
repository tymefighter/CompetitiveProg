#include<iostream>
#include<cmath>

using namespace std;

const double EPS = 1e-5;

struct Point {
    double x, y;

    Point():
        x(0),
        y(0) {}
    
    Point(double x_, double y_):
        x(x_),
        y(y_) {}

    ~Point() {}

    bool operator== (const Point &v) {
        return
            fabs(x - v.x) < EPS
            &&
            fabs(y - v.y) < EPS;
    }
};

struct Line {
    double a, b, c;

    Line():
        a(0),
        b(0),
        c(0) {}

    Line(const Point &u, const Point &v):
        a(u.y - v.y),
        b(v.x - u.x),
        c(u.x * v.y - u.y * v.x) {
            double denom = sqrt(a * a + b * b);
            a /= denom;
            b /= denom;
            c /= denom;
            if(a < 0 || (a == 0 || b < 0)) {
                a = -a;
                b = -b;
                c = -c;
            }
        }

    ~Line() {}
};

struct Seg {
    Point a, b;
    Line l;

    Seg() {}

    Seg(const Point &u, const Point &v):
        a(u),
        b(v),
        l(a, b) {}

    ~Seg() {}
};

Seg u, v;
Line l1, l2;

Point intersection(const Line &u, const Line &v) {
    double denom = u.a * v.b - u.b * v.a;
    return
        Point (
            (v.c * u.b - u.c * v.b) / denom,
            (u.c * v.a - v.c * u.a) / denom
        );
}

void solve() {
    if(u.a == v.b) {
        swap(v.a, v.b);
    }
    else if(u.b == v.a) {
        swap(u.a, u.b);
    }
    else if(u.b == v.b) {
        swap(u.a, u.b);
        swap(v.a, v.b);
    }

    l1.a = u.l.a;
    l1.b = u.l.b;
    l1.c = - (l1.a * v.b.x + l1.b * v.b.y);

    l2.a = v.l.a;
    l2.b = v.l.b;
    l2.c = - (l2.a * u.b.x + l2.b * u.b.y);

    Point p = intersection(l1, l2);
    if(fabs(p.x) < EPS)
        p.x = 0;
    if(fabs(p.y) < EPS)
        p.y = 0;
    printf("%0.3lf %0.3lf\n", p.x, p.y);
}

int main() {

    double x1, y1, x2, y2;
    double x3, y3, x4, y4;

    while(
        cin 
        >> x1 >> y1 >> x2 >> y2
        >> x3 >> y3 >> x4 >> y4
    ) {

        u = Seg (
            Point (x1, y1),
            Point (x2, y2)
        );
        v = Seg (
            Point (x3, y3),
            Point (x4, y4)
        );

        solve();
    }

    return 0;
}