#include<iostream>
#include<cmath>

using namespace std;

const double EPS = 1e-7;

struct Point {
    double x, y;

    Point(double x_, double y_):
        x(x_),
        y(y_) {}

    ~Point() {}
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
            double scale = sqrt(a * a + b * b);
            a /= scale;
            b /= scale;
            c /= scale;

            if(a < EPS || (fabs(a) < EPS && b < -EPS)) {
                a = -a;
                b = -b;
                c = -c;
            }
        }

    ~Line() {}

    bool operator== (const Line &l) const {
        return
            fabs(a - l.a) < EPS
            &&
            fabs(b - l.b) < EPS
            &&
            fabs(c - l.c) < EPS;
    }
};

bool parallel(const Line &l1, const Line &l2) {
    return
        fabs(l1.a - l2.a) < EPS
        &&
        fabs(l1.b - l2.b) < EPS
        &&
        fabs(l1.c - l2.c) > EPS;
}

Point getIntersection(const Line &l1, const Line &l2) {
    double denom = l1.a * l2.b - l2.a * l1.b;
    return Point (
        (l2.c * l1.b - l1.c * l2.b) / denom,
        (- l2.c * l1.a + l1.c * l2.a) / denom
    );
}

void readInput(Line &l1, Line &l2) {
    double x1, y1, x2, y2, x3, y3, x4, y4;

    scanf("%lf %lf %lf %lf ", &x1, &y1, &x2, &y2);
    scanf("%lf %lf %lf %lf ", &x3, &y3, &x4, &y4);

    l1 = Line (
        Point (x1, y1),
        Point (x2, y2)
    );
    l2 = Line (
        Point (x3, y3),
        Point (x4, y4)
    );
}

void solve(const Line &l1, const Line &l2) {
    if(l1 == l2)
        printf("LINE\n");
    else if(parallel(l1, l2))
        printf("NONE\n");
    else {
        Point p = getIntersection(l1, l2);
        printf("POINT %0.2lf %0.2lf\n", p.x, p.y);
    }
}

int main() {
    int t;

    scanf("%d ", &t);
    printf("INTERSECTING LINES OUTPUT\n");
    while(t --) {
        Line l1, l2;
        readInput(l1, l2);
        solve(l1, l2);
    }
    printf("END OF OUTPUT\n");

    return 0;
}