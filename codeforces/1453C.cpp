#include <iostream>

using namespace std;

const int N = 2005;
int n, a[N][N];

void readInput() {
    scanf("%d ", &n);
    
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            char c;
            scanf("%c ", &c);
            a[i][j] = static_cast<int>(c - '0');
        }
    }
}

int minRow[10], maxRow[10];
int minCol[10], maxCol[10];

void findMinMax() {
    for(int i = 0;i < 10;i++)
        minRow[i] = maxRow[i] = minCol[i] = maxCol[i] = -1;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            int d = a[i][j];

            if(minRow[d] == -1) {
                minRow[d] = maxRow[d] = i;
                minCol[d] = maxCol[d] = j;
            }
            else {
                minRow[d] = min(minRow[d], i);
                maxRow[d] = max(maxRow[d], i);
                minCol[d] = min(minCol[d], j);
                maxCol[d] = max(maxCol[d], j);
            }
        }
    }
}

int leftMost[10][N], rightMost[10][N];
int topMost[10][N], bottomMost[10][N];

void findEachRowCol() {
    for(int d = 0;d < 10;d++) {
        for(int i = 0;i < n;i++)
            leftMost[d][i] 
            = rightMost[d][i] 
            = topMost[d][i] 
            = bottomMost[d][i] = -1;
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            int d = a[i][j];
            
            if(leftMost[d][i] == -1)
                leftMost[d][i] = rightMost[d][i] = j;
            else
                rightMost[d][i] = j;
        }
    }

    for(int j = 0;j < n;j++) {
        for(int i = 0;i < n;i++) {
            int d = a[i][j];

            if(topMost[d][j] == -1)
                topMost[d][j] = bottomMost[d][j] = i;
            else
                bottomMost[d][j] = i; 
        }
    }
}

long long solveForDigit(int d) {
    long long ans = 0;

    for(int i = 0;i < n;i++) {
        int l = leftMost[d][i];
        int r = rightMost[d][i];
        long long currArea;

        if(l == -1) continue;

        currArea = max(abs(minRow[d] - i), abs(maxRow[d] - i))
            * static_cast<long long>(max(max(l, n - l - 1), max(r, n - r - 1)));
        
        currArea = max(currArea, max(i, n - i - 1) * static_cast<long long>(r - l));

        ans = max(ans, currArea);
    }

    for(int j = 0;j < n;j++) {
        int u = topMost[d][j];
        int v = bottomMost[d][j];
        long long currArea;

        if(u == -1) continue;

        currArea = max(abs(minCol[d] - j), abs(maxCol[d] - j))
            * static_cast<long long>(max(max(u, n - u - 1), max(v, n - v - 1)));
        
        currArea = max(currArea, max(j, n - j - 1) * static_cast<long long>(v - u));

        ans = max(ans, currArea);
    }

    return ans;
}

void solve() {

    findMinMax();
    findEachRowCol();

    for(int d = 0;d < 10;d++)
        printf("%lld ", solveForDigit(d));

    printf("\n");
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

