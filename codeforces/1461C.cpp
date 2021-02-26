#include <iostream>

using namespace std;

const int N = 100005;
int n, m;
int a[N];

void readSolve() {

    scanf("%d %d ", &n, &m);
    for(int i = 0;i < n;i++)
        scanf("%d ", &a[i]);

    int rMin = n;
    while(rMin > 0 && a[rMin - 1] == rMin) rMin --;
    
    double prob = 1.0;
    for(int i = 0;i < m;i++) {
        int r;
        double p;
        scanf("%d %lf ", &r, &p);

        if(r >= rMin) prob *= (1 - p);
    }

    prob = (rMin == 0 ? 1.0 : 1 - prob);
    printf("%.6lf\n", prob);
}

int main() {
    int t;
    scanf("%d ", &t);

    while(t --) readSolve();

    return 0;
}
