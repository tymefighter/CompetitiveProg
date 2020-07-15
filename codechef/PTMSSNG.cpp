#include<iostream>
#include<map>

using namespace std;

void readSolve() {
    int n;
    map<int, int> mx, my;

    scanf("%d ", &n);
    n = 4 * n - 1;
    for(int i = 0;i < n;i++) {
        int x, y;
        scanf("%d %d ", &x, &y);
        if(mx.find(x) == mx.end())
            mx[x] = 0;
        if(my.find(y) == my.end())
            my[y] = 0;
        
        mx[x] ++;
        my[y] ++;
    }

    for(const pair<int, int> &p : mx) {
        if(p.second % 2 == 1) {
            printf("%d ", p.first);
            break;
        }
    }

    for(const pair<int, int> &p : my) {
        if(p.second % 2 == 1) {
            printf("%d\n", p.first);
            break;
        }
    }
}

int main() {
    int t;
    scanf("%d ", &t);
    while(t --)
        readSolve();
    return 0;
}