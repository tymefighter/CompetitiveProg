#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<sstream>

using namespace std;

double EPS = 1e-9;

struct Point {
    double x, y;

    Point():
        x(0),
        y(0) {}

    Point(double x_, double y_):
        x(x_),
        y(y_) {}

    ~Point() {}

    Point operator+ (const Point &v) const {
        return Point (
            x + v.x,
            y + v.y
        );
    }

    Point operator/ (double div) const {
        return Point (
            x / div,
            y / div
        );
    }

    bool operator== (const Point &v) const {
        return
            fabs(x - v.x) < EPS
            &&
            fabs(y - v.y) < EPS;
    }
};

struct Line {
    double a, b, c;

    void normalize() {
        double div = sqrt(a * a + b * b);
        a /= div;
        b /= div;
        c /= div;
        if(a < 0 || (fabs(a) < EPS && b < 0)) {
            a = -a;
            b = -b;
            c = -c;
        }
    }

    Line():
        a(0),
        b(0),
        c(0) {}

    Line(const Point &u, const Point &v):
        a(u.y - v.y),
        b(v.x - u.x),
        c(u.x * v.y - v.x * u.y) {
            normalize();
        }

    ~Line() {}
};

inline double dist(const Point &u, const Point &v) {
    return hypot(u.x - v.x, u.y - v.y);
}

inline double sq(double x) {return x * x;}

struct Circle {
    Point center;
    double r;

    Circle():
        center(Point ()),
        r(0) {}

    Circle(const Point &center_, double r_):
        center(center_),
        r(r_) {}

    ~Circle() {}

    bool insideOrOn(const Point &p) const {
        double d = dist(center, p);
        return
            d < r
            ||
            fabs(d - r) < EPS;
    }
};

void getCircles(const Point &a, const Point &b, double r, vector<Circle> &c) {
    c.clear();

    if(a == b)
        return;

    double d = dist(a, b);
    if(d > 2 * r)
        return;
    
    Point mid = (a + b) / 2;
    if(fabs(d - 2 * r) < EPS) {
        c.push_back(
            Circle (
                mid,
                r
            )
        );
        return;
    }

    double d1_sq = sq(r) - sq(d / 2);
    Line l(a, b);
    double m = sqrt(d1_sq / (sq(l.a) + sq(l.b)));

    c.push_back(Circle(
        Point (
            mid.x + l.a * m,
            mid.y + l.b * m
        ),
        r
    ));
    c.push_back(Circle(
        Point (
            mid.x - l.a * m,
            mid.y - l.b * m
        ),
        r
    ));
}

int numCovered(const vector<Point> &a, const Circle &c) {
    int nCover = 0;
    for(const Point &p : a)
        nCover += (c.insideOrOn(p) ? 1 : 0);
    return nCover;
}

void readInput(vector<Point> &a) {
    a.clear();

    string line;
    while(getline(cin, line)) {
        if(line == "")
            break;

        stringstream ss(line);
        double x, y;
        ss >> x >> y;
        a.push_back(Point(x, y));
    }
}

int solve(const vector<Point> &a, double r) {
    int n = a.size();

    if(n == 1)
        return 1;

    int maxCovered = 1;
    for(int i = 0;i < n;i++) {
        for(int j = i + 1;j < n;j++) {
            vector<Circle> c;
            getCircles(a[i], a[j], r, c);
            for(const Circle &circle : c)
                maxCovered = max(maxCovered, numCovered(a, circle));
        }
    }

    return maxCovered;
}

int main() {

    int t;
    string line;

    getline(cin, line);
    t = stoi(line);
    getline(cin, line);

    for(int i = 0;i < t;i++) {
        if(i)
            cout << "\n";
        vector<Point> a;
        double r = 2.5;

        readInput(a);
        cout << solve(a, r) << "\n";
    }

    return 0;
}