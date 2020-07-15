#include<iostream>

using namespace std;

const int N = 15;
int n, m;
char a[N][N], ans[N];

void readInput() {
    scanf("%d %d ", &n, &m);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            scanf("%c ", &a[i][j]);
    }
}

int diff[N];

bool checkAns() {
    for(int i = 0;i < n;i++)
        diff[i] = 0;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            diff[i] += (a[i][j] != ans[j] ? 1 : 0);

        if(diff[i] > 1)
            return false;
    }

    return true;
}

void printAns() {
    for(int j = 0;j < m;j++)
        printf("%c", ans[j]);
    printf("\n");
}

void solve() {
    for(int j = 0;j < m;j++)
        ans[j] = a[0][j];

    for(int j = 0;j < m;j++) {
        for(int i = 0;i < n;i++) {
            ans[j] = a[i][j];
            if(checkAns()) {
                printAns();
                return;
            }
        }
        ans[j] = a[0][j];
    }

    printf("-1\n");
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