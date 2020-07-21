#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Point {
    long long x, y;

    bool operator< (const Point &v) const {
        return
            x < v.x
            ||
            (x == v.x && y < v.y);
    }
};

int n;
vector<Point> a, b;

void readInput() {
    scanf("%d ", &n);
    a.clear();
    a.resize(n);
    b.clear();
    b.resize(n);
    for(int i = 0;i < n;i++)
        scanf("%lld %lld ", &a[i].x, &a[i].y);
    for(int i = 0;i < n;i++)
        scanf("%lld %lld ", &b[i].x, &b[i].y);
}

void rotate(Point &u) {
    swap(u.x, u.y);
    u.x = -u.x;
}

void rotatePoints() {
    for(int i = 0;i < n;i++)
        rotate(a[i]);
}

bool checkEqual() {
    sort(a.begin(), a.end());
    long long x = b[0].x - a[0].x, y = b[0].y - a[0].y;

    for(int i = 1;i < n;i++) {
        if(
            b[i].x - a[i].x != x
            ||
            b[i].y - a[i].y != y
        )
            return false;
    }

    return true;
}

bool solve() {
    sort(b.begin(), b.end());

    if(checkEqual())
        return true;

    for(int i = 0;i < 3;i++) {
        rotatePoints();
        if(checkEqual())
            return true;
    }

    return false;
}

int main() {
    int t;
    scanf("%d ", &t);
    while(t --) {
        readInput();
        if(solve())
            printf("MATCHED\n");
        else
            printf("NOT MATCHED\n");
    }

    return 0;
}