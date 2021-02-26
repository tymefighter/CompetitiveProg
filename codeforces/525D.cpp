#include<iostream>
#include<queue>

using namespace std;

const int N = 2005;

int n, m;
char a[N][N];
queue<pair<int, int> > q;

void readInput() {
    scanf("%d %d ", &n, &m);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            scanf("%c ", &a[i][j]);
    }
}

bool squareContOneAsterisk(int r, int c) {
    if(r < 0 || c < 0 || r + 1 >= n || c + 1 >= m)
        return false;
    
    int numAst = 0;
    for(int i = 0;i < 2;i++) {
        for(int j = 0;j < 2;j++)
            numAst += (a[r + i][c + j] == '*' ? 1 : 0);
    }

    return numAst == 1;
}

bool shouldBeRemoved(int i, int j) {
    return
        a[i][j] == '*'
        &&
        (squareContOneAsterisk(i, j)
        ||
        squareContOneAsterisk(i - 1, j)
        ||
        squareContOneAsterisk(i, j - 1)
        ||
        squareContOneAsterisk(i - 1, j - 1));
}

void solve() {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(shouldBeRemoved(i, j)) {
                q.push({i, j});
                a[i][j] = '.';
            }
        }
    }

    static int ar[] = {0, 0, -1, 1, -1, 1, -1, 1};
    static int ac[] = {-1, 1, 0, 0, -1, -1, 1, 1};

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0;i < 8;i++) {
            int rd = r + ar[i];
            int cd = c + ac[i];
            if(rd >= 0 && rd < n && cd >= 0 && cd < m 
                && shouldBeRemoved(rd, cd)) {
                q.push({rd, cd});
                a[rd][cd] = '.';
            }
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            printf("%c", a[i][j]);
        printf("\n");
    }
}

int main() {

    readInput();
    solve();

    return 0;
}