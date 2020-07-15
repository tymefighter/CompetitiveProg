#include<iostream>

using namespace std;

const int N = 305;
int a[N][N];

void readSolve() {
    int n, m;
    scanf("%d %d ", &n, &m);

    bool noAnswer = false;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            int x;
            scanf("%d ", &x);

            if(noAnswer)
                continue;
            
            if((i == 0 && j == 0) || (i == 0 && j == m - 1)
                || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
                if(x > 2)
                    noAnswer = true;
                else
                    a[i][j] = 2;
            }
            else if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if(x > 3)
                    noAnswer = true;
                else
                    a[i][j] = 3;
            }
            else {
                if(x > 4)
                    noAnswer = true;
                else
                    a[i][j] = 4;
            }
        }
    }

    if(noAnswer)
        printf("NO\n");
    else {
        printf("YES\n");
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++)
                printf("%d ", a[i][j]);
            printf("\n");
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