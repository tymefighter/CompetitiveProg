#include<iostream>

using namespace std;

const int N = 305;
int n, m, r1, c1, r2, c2;
double prob[N][N];

void initProb() {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            prob[i][j] = -1.0;
    }
}

double computeProb(int r, int c) {

    if(r == n - 1 && c == m - 1)
        return 1.0;

    if(r >= r1 && r <= r2 && c >= c1 && c <= c2)
        return 0;
    
    if(prob[r][c] >= 0)
        return prob[r][c];

    if(r == n - 1)
        prob[r][c] = computeProb(r, c + 1);
    else if(c == m - 1)
        prob[r][c] = computeProb(r + 1, c);
    else
        prob[r][c] = (computeProb(r, c + 1) + computeProb(r + 1, c)) / 2;

    return prob[r][c];
}

int main() {

    int t;
    cin >> t;
    for(int i = 1;i <= t;i++) {
        cin >> m >> n >> c1 >> r1 >> c2 >> r2;
        c1 --, r1 --;
        c2 --, r2 --;
        initProb();
        printf("Case #%d: %lf\n", i, computeProb(0, 0));
    }

    return 0;
}