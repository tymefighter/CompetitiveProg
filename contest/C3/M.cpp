#include<iostream>
#include<cmath>

using namespace std;

const double EPS = 1e-8;

struct Point {
    double x, y;

    Point():
        x(0),
        y(0) {}

    Point(double x_, double y_):
        x(x_),
        y(y_) {}

    ~Point() {}
};

struct Vec {
    double x, y;
    
    Vec(const Point &a, const Point &b):
        x(b.x - a.x),
        y(b.y - a.y) {}

    Vec(const Point &a):
        x(a.x),
        y(a.y) {}

    ~Vec() {}

    Vec operator+(const Vec &u) {
        return Vec (Point (
            x + u.x,
            y + u.y
        ));
    }

    Vec operator*(double lambda) {
        return Vec (Point (
            x * lambda,
            y * lambda
        ));
    }
};

Point A, B, C;
Point D, E, F;
double area;

double dist(const Point &u, const Point &v) {
    return hypot(u.x - v.x, u.y - v.y);
}

double dot(const Vec &u, const Vec &v) {
    return u.x * v.x + u.y * v.y;
}

double norm(const Vec &u) {
    return hypot(u.x, u.y);
}

double computeCosAngle(const Vec &u, const Vec &v) {
    return
        (dot(u, v) / norm(u)) / norm(v);
}

void computeArea() {
    double a = dist(D, E);
    double b = dist(E, F);
    double c = dist(F, D);
    double s = (a + b + c) / 2.;

    area = sqrt(s) * sqrt(s - a) * sqrt(s - b) * sqrt(s - c);
}

void solve() {
    computeArea();
    Vec AC = Vec(A, C);
    Vec AB = Vec(A, B);
    double cosAngle = computeCosAngle(AC, AB);
    double sinAngle = sqrt(1 - cosAngle * cosAngle);
    double l = area / (norm(AB) * sinAngle);
    double lambda = l / norm(AC);

    Vec H = Vec(A) + AC * lambda;
    Vec G = Vec(B) + AC * lambda;

    printf("%0.3lf %0.3lf %0.3lf %0.3lf\n", G.x, G.y, H.x, H.y);
}

int main() {
    while(
        cin 
        >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y
        >> D.x >> D.y >> E.x >> E.y >> F.x >> F.y
    ) {
        if(
            fabs(A.x) < EPS
            &&
            fabs(A.y) < EPS
            &&
            fabs(B.x) < EPS
            &&
            fabs(B.y) < EPS
            &&
            fabs(C.x) < EPS
            &&
            fabs(C.y) < EPS
            &&
            fabs(D.x) < EPS
            &&
            fabs(D.y) < EPS
            &&
            fabs(E.x) < EPS
            &&
            fabs(E.y) < EPS
            &&
            fabs(F.x) < EPS
            &&
            fabs(F.y) < EPS
        )
            break;
        
        solve();
    }

    return 0;
}