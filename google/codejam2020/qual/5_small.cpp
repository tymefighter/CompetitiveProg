#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5;
int n, k;
int a[N][N];

bool fillLastRowAndcheckMat() {
    static bool seen[N + 1];

    for(int c = 0;c < n;c++) {
        
        for(int i = 1;i <= N;i++)
            seen[i] = false;
        
        for(int r = 0;r < n - 1;r++) {
            if(seen[a[r][c]])
                return false;
            
            seen[a[r][c]] = true;
        }

        for(int i = 1;i <= N;i++) {
            if(!seen[i]) {
                a[n - 1][c] = i;
                seen[i] = true;
                break;
            }
        }
    }

    int sumVal = 0;
    for(int i = 0;i < n;i++)
        sumVal += a[i][i];

    if(sumVal != k)
        return false;

    return true;
}

bool buildRow(int r) {
    if(r == n - 1) {

        if(fillLastRowAndcheckMat())
            return true;
        else
            return false;
    }

    for(int c = 0;c < n;c++)
        a[r][c] = c + 1;
    
    bool notAnalysedAllPermutations = true;

    while(notAnalysedAllPermutations) {
        if(buildRow(r + 1))
            return true;
        notAnalysedAllPermutations = next_permutation(a[r], a[r] + n);
    }

    return false;
}

void printMat() {
    for(int r = 0;r < n;r++) {
        for(int c = 0;c < n;c++)
            printf("%d ", a[r][c]);
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1;i <= t;i++) {
        scanf("%d %d", &n, &k);
        if(buildRow(0)) {
            printf("Case #%d: POSSIBLE\n", i);
            printMat();
        }
        else
            printf("Case #%d: IMPOSSIBLE\n", i);
    }
    return 0;
}