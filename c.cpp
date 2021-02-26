#include <iostream>
#include <cassert>

using namespace std;

const int N = 105;
int n, m, a[N][N];

void readInput() {
    scanf("%d %d ", &n, &m);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            scanf("%d ", &a[i][j]);
    }
}

void solve() {
    bool startOdd = true;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            int currVal;
            if(startOdd) {
                if((j & 1) == 0)
                    currVal = ((a[i][j] & 1) == 1 ? a[i][j] : a[i][j] + 1);
                else
                    currVal = ((a[i][j] & 1) == 1 ? a[i][j] + 1 : a[i][j]); 
            }
            else {
                if((j & 1) == 0)
                    currVal = ((a[i][j] & 1) == 1 ? a[i][j] + 1 : a[i][j]);
                else
                    currVal = ((a[i][j] & 1) == 1 ? a[i][j] : a[i][j] + 1); 
            }

            printf("%d ", currVal);
        }
        startOdd = !startOdd;
        printf("\n");
    }
}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        readInput();
        solve();
    }

    return 0;
}

