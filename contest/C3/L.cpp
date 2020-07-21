#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

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

    bool operator< (const Point &v) const {
        return
            (x < v.x)
            ||
            (x == v.x && y < v.y);
    }
};

struct Line {
    long long a, b, c;

    private:
        long long gcd(long long u, long long v) {
            if(u == 0)
                return v;
            return gcd(v % u, u);
        }

    public:

        Line():
            a(0),
            b(0),
            c(0) {}

        Line(const Point &u, const Point &v):
            a(u.y - v.y),
            b(v.x - u.x),
            c(u.x * v.y - u.y * v.x) {
                long long g = gcd(a, gcd(b, c));
                a /= g;
                b /= g;
                c /= g;
                if(a < 0 || (a == 0 && b < 0)) {
                    a = -a;
                    b = -b;
                    c = -c;
                }
            }

        ~Line() {}
};

struct Seg {
    Point a, b; // a has y coord bigger than b
    Line l;

    Seg() {}

    Seg(const Point &a_, const Point &b_):
        a(a_),
        b(b_),
        l(a, b) {}

    ~Seg() {}

    double getX(long long y) const {
        return - (l.b * y + l.c) / static_cast<double>(l.a);
    }
};

inline double dist(double x1, double y1, double x2, double y2) {
    return hypot(x1 - x2, y1 - y2);
}

void readInput(vector<Seg> &seg) {
    int n;
    vector<Point> pts;
    scanf("%d ", &n);
    
    pts.resize(n);
    for(int i = 0;i < n;i++)
        scanf("%lld %lld ", &pts[i].x, &pts[i].y);

    sort(pts.begin(), pts.end());

    Point prev(pts[0].x, pts[0].y);

    for(int i = 1;i < n;i++) {
        if(pts[i].y < prev.y)
            seg.push_back(Seg (
                prev,
                Point(pts[i].x, pts[i].y)
            ));
        
        prev = Point(pts[i].x, pts[i].y);
    }    
}

void solve(vector<Seg> &seg) {
    reverse(seg.begin(), seg.end());
    long long currY = 0;
    double totalLength = 0;

    for(const Seg &s : seg) {
        if(s.a.y < currY)
            continue;

        double x = s.getX(currY);
        totalLength += dist(s.a.x, s.a.y, x, currY);
        currY = s.a.y;
    }

    printf("%0.2lf\n", totalLength);
}

int main() {
    int t;
    scanf("%d ", &t);
    while(t --) {
        vector<Seg> seg;
        readInput(seg);
        solve(seg);
    }

    return 0;
}