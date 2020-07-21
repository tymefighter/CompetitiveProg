#include<iostream>

using namespace std;

struct Point {
    long long x, y;

    Point():
        x(0),
        y(0) {}

    Point(long long x_, long long y_):
        x(x_),
        y(y_) {}

    ~Point() {}

    bool operator== (const Point &p) const {
        return (x == p.x) && (y == p.y);
    }
};

struct Line {
    long long a, b, c;

    Line(const Point &u, const Point &v):
        a(u.y - v.y),
        b(v.x - u.x),
        c(u.x * v.y - v.x * u.y) {}

    ~Line() {}

    long long evaluate(const Point &p) const {
        return a * p.x + b * p.y + c;
    }

    int evaluateSign(const Point &p) const {
        long long eval = evaluate(p);
        if(eval < 0)
            return -1;
        else if(eval > 0)
            return 1;
        else
            return 0;
    }
};

struct Seg {
    Point a, b;

    Seg() {}

    Seg(const Point &u, const Point &v):
        a(u),
        b(v) {}

    ~Seg() {}

    bool containsPoint(const Point &p) const {
        return
            ((Line (a, b)).evaluate(p) == 0)
            &&
            (min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x))
            &&
            (min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y));
    }
};

struct Rectangle {
    Point a, b, c, d;

    Rectangle() {}
    
    Rectangle(const Point &u, const Point &v):
        a(u),
        b(u.x, v.y),
        c(v),
        d(v.x, u.y) {}

    ~Rectangle() {}

    bool isInteriorPoint(const Point &p) const {
        return 
            (min(a.x, c.x) <= p.x && p.x <= max(a.x, c.x))
            &&
            (min(a.y, c.y) <= p.y && p.y <= max(a.y, c.y));
    }
};

void readInput(Rectangle &sq, Seg &seg) {
    long long xstart, ystart, xend, yend;
    long long xleft, ytop, xright, ybottom;
    scanf("%lld %lld %lld %lld ", &xstart, &ystart, &xend, &yend);
    scanf("%lld %lld %lld %lld ", &xleft, &ytop, &xright, &ybottom);

    seg = Seg (
        Point (xstart, ystart),
        Point (xend, yend)
    );
    sq = Rectangle (
        Point (xleft, ytop),
        Point (xright, ybottom)
    );
}

bool lineSegIntersect(const Seg &u, const Seg &v) {
    if(u.containsPoint(v.a) || u.containsPoint(v.b)
        || v.containsPoint(u.a) || v.containsPoint(u.b))
        return true;

    if(u.a == u.b || v.a == v.b)
        return false;

    Line l1(u.a, u.b), l2 (v.a, v.b);

    return
        (l1.evaluateSign(v.a) * l1.evaluateSign(v.b) < 0)
        &&
        (l2.evaluateSign(u.a) * l2.evaluateSign(u.b) < 0);
}

bool intersect(const Rectangle &sq, const Seg &seg) {
    return
        (
            sq.isInteriorPoint(seg.a)
            &&
            sq.isInteriorPoint(seg.b)
        )
        ||
        lineSegIntersect (
            Seg (sq.a, sq.b),
            seg
        )
        ||
        lineSegIntersect (
            Seg (sq.b, sq.c),
            seg
        )
        ||
        lineSegIntersect (
            Seg (sq.c, sq.d),
            seg
        )
        ||
        lineSegIntersect (
            Seg (sq.d, sq.a),
            seg
        );
}

int main() {
    int t;
    scanf("%d ", &t);
    while(t --) {
        Rectangle sq;
        Seg seg;
        readInput(sq, seg);
        if(intersect(sq, seg))
            printf("T\n");
        else
            printf("F\n");
    }
    return 0;
}