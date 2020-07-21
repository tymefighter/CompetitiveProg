#include<iostream>
#include<vector>
#include<map>
#include<cassert>

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
            x < v.x
            ||
            (x == v.x && y < v.y);
    }

    bool operator== (const Point &v) const {
        return
            x == v.x
            &&
            y == v.y;
    }
};

struct Line {
    long long a, b, c;

    private:
        long long gcd(long long x, long long y) {
            if(x == 0)
                return y;
            return gcd(y % x, x);
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
    Point a, b;
    Line l;

    Seg() {}

    Seg(const Point &a_, const Point &b_):
        a(a_),
        b(b_),
        l(a, b) {}

    ~Seg() {}

    pair<bool, double> getY(long long x) const {
        if(x < min(a.x, b.x) || x > max(a.x, b.x))
            return {false, 0};
        
        assert(l.b != 0);

        return {true, - (l.a * x + l.c) / static_cast<double>(l.b)};
    }
};

void readInput(vector<Seg> &seg, vector<Point> &source) {
    int np, ns;

    scanf("%d ", &np);
    seg.clear();
    seg.resize(np);

    for(int i = 0;i < np;i++) {
        long long x1, y1, x2, y2;
        scanf("%lld %lld %lld %lld ", &x1, &y1, &x2, &y2);
        seg[i] = Seg(
            Point(x1, y1),
            Point(x2, y2)
        );
    }

    scanf("%d ", &ns);
    source.clear();
    source.resize(ns);

    for(int i = 0;i < ns;i++) {
        long long x, y;
        scanf("%lld %lld ", &x, &y);
        source[i] = Point(x, y);
    }
}

long long computeDP(
    map<Point, 
    long long> &dp, 
    Point p, 
    const vector<Seg> &seg
) {
    if(dp.find(p) != dp.end())
        return dp[p];

    double maxHt = -1;
    Point next;

    for(const Seg &s : seg) {
        pair<bool, double> val = s.getY(p.x);
        if(val.first && val.second < static_cast<double>(p.y)) {
            if(maxHt == -1 || val.second > maxHt) {
                maxHt = val.second;
                next = (s.a.y < s.b.y ? s.a : s.b);
            }
        }
    }

    if(maxHt == -1)
        dp[p] = p.x;
    else
        dp[p] = computeDP(dp, next, seg);

    return dp[p];
}

void solve(const vector<Seg> &seg, const vector<Point> &source) {
    // dp[p]: x coord of the point where it would fall if p is source
    map<Point, long long> dp;

    for(const Point &p : source)
        printf("%lld\n", computeDP(dp, p, seg));
}

int main() {

    int t;
    scanf("%d ", &t);
    
    for(int i = 0;i < t;i++) {
        if(i)
            printf("\n");
        vector<Seg> seg;
        vector<Point> source;
        readInput(seg, source);
        solve(seg, source);
    }

    return 0;
}