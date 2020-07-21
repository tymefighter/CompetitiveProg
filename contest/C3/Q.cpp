#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

struct Point {
    long long x, y, z;

    Point():
        x(0),
        y(0),
        z(0) {}

    Point(long long x_, long long y_, long long z_):
        x(x_),
        y(y_),
        z(z_) {}

    ~Point() {}

    bool operator< (const Point &v) const {
        return
            x < v.x
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

        void normalize() {
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
    public:
        Line():
            a(0),
            b(0),
            c(0) {}

        Line(const Point &u, const Point &v):
            a(u.y - v.y),
            b(v.x - u.x),
            c(u.x * v.y - u.y * v.x) {
                normalize();
            }

        Line(const Point &u, const Line &l):
            a(-l.b),
            b(l.a),
            c(- (l.a * u.x + l.b * u.y)) {
                normalize();
            }

        ~Line() {}

        bool operator< (const Line &v) const {
            return
                (a < v.a)
                ||
                (a == v.a && b < v.b)
                ||
                (a == v.a && b == v.b && c < v.c);
        }

        bool operator== (const Line &v) const {
            return
                a == v.a
                ||
                b == v.b
                ||
                c == v.c;
        }

        long long evaluate(const Point &u) {
            return a * u.x + b * u.y + c;
        }
};

const Point zero(0, 0, 0);

int n;
map<Line, vector<Point> > m;

void readInput() {
    m.clear();
    for(int i = 0;i < n;i++) {
        long long x, y, z;
        cin >> x >> y >> z;
        Point pt(x, y, z);

        m[Line(pt, zero)].push_back(pt);
    }
}

bool comp(const Point &u, const Point &v) {
    return
        hypot(u.x, u.y) < hypot(v.x, v.y);
}

void solve() {
    vector<Point> ans;
    for(const pair<Line, vector<Point> > &p : m) {
        Line perpLine (zero, p.first);
        long long maxHt1 = -1, maxHt2 = -1;
        vector<Point> a = p.second;
        
        sort(a.begin(), a.end(), comp);
        for(const Point &pt : a) {
            if(perpLine.evaluate(pt) > 0) {
                if(pt.z <= maxHt1)
                    ans.push_back(pt);
                else
                    maxHt1 = pt.z;
            }
            else {
                if(pt.z <= maxHt2)
                    ans.push_back(pt);
                else
                    maxHt2 = pt.z;
            }
        }
    }

    if(ans.size() == 0) {
        printf("All the lights are visible.\n");
        return;
    }
    else {
        printf("Some lights are not visible:\n");
        sort(ans.begin(), ans.end());
        for(int i = 0;i < ans.size();i++) {
            if(i)
                printf(";\n");
            printf("x = %lld, y = %lld", ans[i].x, ans[i].y);
        }
        printf(".\n");
    }
}

int main() {

    int t = 1;
    while(cin >> n) {
        if(!n)
            break;
        printf("Data set %d:\n", t);
        readInput();
        solve();
        t ++;
    }

    return 0;
}