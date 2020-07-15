#include<iostream>
#include<cmath>

using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;

    Point():
        x(0),
        y(0) {}

    Point(double x_, double y_):
        x(x_),
        y(y_) {}
    
    ~Point() {}

    Point operator+ (const Point &v) {
        return Point(
            x + v.x,
            y + v.y
        );
    }

    Point operator- (const Point &v) {
        return Point {
            x - v.x,
            y - v.y
        };
    }

    bool operator== (const Point &v) {
        return
            (fabs(x - v.x) <= EPS) && (fabs(y - v.y) <= EPS);
    }

    bool operator< (const Point &v) {
        if(fabs(x - v.x) > EPS)
            return x < v.x;
        else
            return y < v.y;
    }
};

enum AngleUnit {RAD, DEG};

double dist(const Point &u, const Point &v) {
    return hypot(u.x - v.x, u.y - v.y);
}

double deg2rad(double theta) {return theta * (M_PI / 180.)}

Point rotate(const Point &p, double theta, AngleUnit angleUnit) {
    if(angleUnit == DEG)
        theta = deg2rad(theta);

    return Point (
        p.x * cos(theta) - p.y * sin(theta),
        p.x * sin(theta) + p.y * cos(theta)
    );
}