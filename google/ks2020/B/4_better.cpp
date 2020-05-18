#include<iostream>
#include<cmath>

using namespace std;

int n, m, r1, c1, r2, c2;

long long fact(int x) {
    long long val = 1;
    for(int i = 2;i <= x;i++)
        val *= i;
    return val;
}

double computeProb() {

    double a1 = 0, a2 = 0;

    if(r2 < n - 1) {
        for(int u = 1;u <= c1;u++)
            a1 += (fact(r2 + 1 + u - 1) / (static_cast<double>(fact(r2 + 1)) * static_cast<double>(fact(u - 1)))) / pow(2, r2 + 1 + u - 1);
    }

    if(c2 < m - 1) {
        for(int u = 1;u <= r1;u++)
            a2 += (fact(c2 + 1 + u - 1) / (static_cast<double>(fact(c2 + 1)) * static_cast<double>(fact(u - 1)))) / pow(2, c2 + 1 + u - 1);
    }

    return a1 + a2;
}

int main() {

    int t;
    cin >> t;
    for(int i = 1;i <= t;i++) {
        cin >> m >> n >> c1 >> r1 >> c2 >> r2;
        c1 --, r1 --;
        c2 --, r2 --;
        printf("Case #%d: %lf\n", i, computeProb());
    }

    return 0;
}