#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

const double INF = 1e15;

int n;
vector<pair<string, string> > ops;

void readInput() {
    cin >> n;
    ops.clear();
    ops.resize(n);
    for(int i = 0;i < n;i++)
        cin >> ops[i].first >> ops[i].second;
}

inline double deg2rad(double angle) {
    return M_PI * (angle / 180);
}

void performFromCurr(double &x, double &y, double &currAngle, int &i) {
    for(;i < ops.size();i++) {
        if(ops[i].second == "?")
            break;
        double val = stoi(ops[i].second);

        if(ops[i].first == "fd") {
            x += val * cos(deg2rad(currAngle));
            y += val * sin(deg2rad(currAngle));
        }
        else if(ops[i].first == "bk") {
            x -= val * cos(deg2rad(currAngle));
            y -= val * sin(deg2rad(currAngle));
        }
        else if(ops[i].first == "lt") {
            currAngle += val;
            if(currAngle >= 360)
                currAngle -= 360;
        }
        else if(ops[i].first == "rt") {
            currAngle -= val;
            if(currAngle < 0)
                currAngle += 360;
        }
    }
}

void solve() {
    int i = 0;
    double x = 0, y = 0, currAngle = 0;
    performFromCurr(x, y, currAngle, i);

    if(ops[i].first == "fd" || ops[i].first == "bk") {
        i ++;
        performFromCurr(x, y, currAngle, i);
        cout << hypot(x, y) << "\n";
    }
    else {
        double err = INF;
        int ansAngle = -1;
        for(int j = 0;j < 360;j++) {
            int idx = i;
            double x1 = x, y1 = y, currAngle1 = currAngle, currErr;
            ops[idx].second = to_string(static_cast<long long>(j));
            performFromCurr(x1, y1, currAngle1, idx);
            currErr = fabs(x1) + fabs(y1);
            if(currErr < err) {
                err = currErr;
                ansAngle = j;
            }
        }
        cout << ansAngle << "\n";
    }
}

int main() {

    int t;

    cin >> t;
    while(t --) {
        readInput();
        solve();
    }

    return 0;
}