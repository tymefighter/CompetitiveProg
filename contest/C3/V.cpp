#include<iostream>
#include<cmath>

using namespace std;

const double PI = 2 * acos(0);

int main() {
    int t;
    scanf("%d ", &t);
    while(t --) {
        double d, l;
        scanf("%lf %lf ", &d, &l);
        printf("%0.3lf\n", PI * sqrt(l * l - d * d) * (l / 4));
    }
    return 0;
}