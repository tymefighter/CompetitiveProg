#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<unordered_set>
#include<set>

using namespace std;

pair<long long, long long> operator-(const pair<long long, long long> &p1, const pair<long long, long long> &p2) {
    return {p1.first - p2.first, p1.second - p2.second};
}

ostream &operator<<(ostream &os, const pair<long long, long long> &p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

const double EPS = 1e-5;

int q;
vector<pair<long long, long long> > a;

// Read Input

void readInput() {
    int n;
    scanf("%d %d ", &n, &q);
    set<pair<long long, long long> > point_seen;

    for(int i = 0;i < n;i++) {
        long long x, y;
        scanf("%lld %lld ", &x, &y);
        point_seen.insert({x, y});
    }

    a.clear();
    for(const pair<long long, long long> &pt : point_seen)
        a.push_back(pt);
}

// Build Layers

vector<vector<pair<long long, long long> > > layers;
pair<long long, long long> pivot;

long long pseudo_cross(const pair<long long, long long> &u, const pair<long long, long long> &v) {
    return u.first * v.second - u.second * v.first;
}

bool is_collinear(const pair<long long, long long> &u, const pair<long long, long long> &v, const pair<long long, long long> &w) {
    return pseudo_cross(v - u, w - u) == 0;
}

bool ccw(const pair<long long, long long> &u, const pair<long long, long long> &v, const pair<long long, long long> &w) {

    return pseudo_cross(v - u, w - u) > 0;
}

double dist(const pair<long long, long long> &u, const pair<long long, long long> &v) {
    double d = static_cast<double>(u.first - v.first) * (u.first - v.first)
        + static_cast<double>(u.second - v.second) * (u.second - v.second);
    return sqrt(d);
}

bool angle_compare(const pair<long long, long long> &u, const pair<long long, long long> &v) {
    if(is_collinear(pivot, u, v))
        return dist(pivot, u) < dist(pivot, v);

    double d1x = u.first - pivot.first, d1y = u.second - pivot.second;
    double d2x = v.first - pivot.first, d2y = v.second - pivot.second;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

bool checkAllCollinear() {
    for(int i = 3;i < a.size();i++) {
        if(!is_collinear(a[i - 2], a[i - 1], a[i]))
            return false;
    }

    return true;
}

void GrahamScan() {
    if(checkAllCollinear()) {
        a.clear();
        return;
    }

    // Find Pivot
    int pivot_idx = 0, n = a.size();
    for(int i = 1;i < n;i++) {
        if(a[i].second < a[pivot_idx].second
            || (a[i].second == a[pivot_idx].second && a[i].first > a[pivot_idx].first))
            pivot_idx = i;
    }

    // Sort based on angle from pivot
    swap(a[0], a[pivot_idx]);
    pivot = a[0];
    sort(a.begin() + 1, a.end(), angle_compare);

    vector<int> s;
    s.push_back(n - 1);
    s.push_back(0);

    for(int i = 1;i < n;i++) {
        int j = static_cast<int>(s.size()) - 1;

        while(!ccw(a[s[j - 1]], a[s[j]], a[i])) {
            s.pop_back();
            j --;
        }

        s.push_back(i);
    }
    
    // (n - 1) is pushed back twice
    
    layers.push_back(vector<pair<long long, long long> >());
    unordered_set<int> chosen;
    
    for(int idx : s) {
        chosen.insert(idx);
        layers[layers.size() - 1].push_back(a[idx]);
    }

    vector<pair<long long, long long> > interior_pt;
    for(int i = 0;i < n;i++) {
        if(chosen.find(i) == chosen.end())
            interior_pt.push_back(a[i]);
    }

    a = interior_pt;
}

void buildLayers() {                                                    // Repeated Graham Scan
    layers.clear();
    while(a.size() > 0)
        GrahamScan();

    for(int i = 0;i < layers.size();i++) {
        for(pair<long long, long long> p : layers[i])
            cout << p << " ";
        cout << "\n";
    }
}

// Answer Queries

double dot(const pair<long long, long long> &u, const pair<long long, long long> &v) {
    return u.first * v.first + u.second * v.second; 
}

double norm(const pair<long long, long long> &u) {
    return sqrt(dot(u, u));
}

double angle(const pair<long long, long long> &u, const pair<long long, long long> &v, const pair<long long, long long> &w) {
    pair<long long, long long> vu = u - v, vw = w - v;
    return acos(dot(vu, vw) / (norm(vu) * norm(vw)));
}

bool doesLayerContainPoint(int layer_idx, const pair<long long, long long> &p) {    // Winding Number Algorithm
    const vector<pair<long long, long long> > poly = layers[layer_idx];
    if(poly.size() == 0)
        return false;

    double angle_sum = 0;
    for(int i = 0;i < static_cast<int>(poly.size()) - 1;i++) { // assume last and first point are same
        if(ccw(p, poly[i], poly[i + 1]))
            angle_sum += angle(poly[i], p, poly[i + 1]);
        else if(is_collinear(p, poly[i], poly[i + 1]))
            return false;
        else
            angle_sum -= angle(poly[i], p, poly[i + 1]);
    }

    return fabs(fabs(angle_sum) - 2 * M_PI) < EPS;
}

int getNumberOfLayers(const pair<long long, long long> &query_point) {              // Binary Search
    int low = 0, high = layers.size() - 1, mid, ansIdx = -1;

    while(low <= high) {
        mid = (low + high) >> 1;
        if(doesLayerContainPoint(mid, query_point)) {
            ansIdx = max(mid, ansIdx);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ansIdx + 1;
}

void solve_queries() {
    while(q --) {
        pair<long long, long long> query_point;
        scanf("%lld %lld ", &query_point.first, &query_point.second);
        printf("%d\n", getNumberOfLayers(query_point));
    }
}

// Main

int main() {
    int t;
    scanf("%d ", &t);
    while(t --) {
        readInput();
        buildLayers();
        solve_queries();
    }
    return 0;
}