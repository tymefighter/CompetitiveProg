#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<int> > a;

void read() {
    
    scanf("%d %d", &n, &m);

    a.clear();
    a.assign(n, vector<int>(m));

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

double getAverageCompass(int r, int c) {

    double avg = 0.0;
    int i, j, ct = 0;

    i = r - 1, j = c;
    // top neighbour
    while(i >= 0) {
        if(a[i][j] != -1)
            break;
        i --;
    }
    if(i != -1) {
        avg += static_cast<double>(a[i][j]);
        ct ++;
    }

    i = r + 1, j = c;
    // bottom neighbour
    while(i < n) {
        if(a[i][j] != -1)
            break;
        i ++;
    }
    if(i != n) {
        avg += static_cast<double>(a[i][j]);
        ct ++;
    }

    i = r, j = c - 1;
    // left neighbour
    while(j >= 0) {
        if(a[i][j] != -1)
            break;
        j --;
    }
    if(j != -1) {
        avg += static_cast<double>(a[i][j]);
        ct ++;
    }

    i = r, j = c + 1;
    // right neighbour
    while(j < m) {
        if(a[i][j] != -1)
            break;
        j ++;
    }
    if(j != m) {
        avg += static_cast<double>(a[i][j]);
        ct ++;
    }

    avg /= static_cast<double>(ct);
    return avg;
}

void solve(int case_no) {

    long long ans = 0;
    bool someEliminated = true;
    vector<vector<int> > temp;

    while(someEliminated) {
        someEliminated = false;
        temp = a;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(a[i][j] == -1)
                    continue;

                ans += a[i][j];

                double avg = getAverageCompass(i, j);
                double curr = static_cast<double>(a[i][j]);
                if(curr < avg) {
                    temp[i][j] = -1;
                    someEliminated = true;
                }
            }
        }
        a = temp;
    }

    printf("Case #%d: %lld\n", case_no, ans);
}

int main() {

    int t;
    scanf("%d", &t);
    for(int i = 1;i <= t;i++) {
        read();
        solve(i);
    }

    return 0;
}