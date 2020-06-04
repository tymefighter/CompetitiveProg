#include<iostream>

using namespace std;

const int N = 1005;
int n, m;
char a[N][N];
bool visited[N][N];

void readInput() {
    scanf("%d %d ", &n, &m);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            scanf("%c ", &a[i][j]);
            visited[i][j] = false;
        }
    }
}

bool blackExistRow[N], blackExistCol[N];
bool existWhiteCol, existWhiteRow;

bool checkGrid() {
    existWhiteCol = existWhiteRow = false;

    // check each row for discontinuity
    for(int i = 0;i < n;i++) {
        blackExistRow[i] = false;

        bool sawBlack = (a[i][0] == '#');
        bool allWhite = !sawBlack;

        for(int j = 1;j < m;j++) {
            if(sawBlack && a[i][j] == '#' && a[i][j - 1] == '.')
                return false;
            if(a[i][j] == '#')
                sawBlack = true;
            allWhite &= (a[i][j] == '.');
        }
        blackExistRow[i] = sawBlack;
        existWhiteRow |= allWhite;
    }

    // check each column for discontinuity
    for(int j = 0;j < m;j++) {
        blackExistCol[j] = false;

        bool sawBlack = (a[0][j] == '#');
        bool allWhite = !sawBlack;

        for(int i = 1;i < n;i++) {
            if(sawBlack && a[i][j] == '#' && a[i - 1][j] == '.')
                return false;
            if(a[i][j] == '#')
                sawBlack = true;
            allWhite &= (a[i][j] == '.');
        }
        blackExistCol[j] = sawBlack;
        existWhiteCol |= allWhite;
    }

    if(existWhiteRow) {
        bool valid = false;
        for(int j = 0;j < m;j++) {
            if(!blackExistCol[j]) {
                valid = true;
                break;
            }
        }

        if(!valid)
            return false;
    }

    if(existWhiteCol) {
        bool valid = false;
        for(int i = 0;i < n;i++) {
            if(!blackExistRow[i]) {
                valid = true;
                break;
            }
        }

        if(!valid)
            return false;
    }

    return true;
}

int ar[] = {1, -1, 0, 0};
int ac[] = {0, 0, 1, -1};

void dfs(int i, int j) {
    visited[i][j] = true;

    for(int k = 0;k < 4;k++) {
        int next_i = i + ar[k], next_j = j + ac[k];
        if(next_i >= 0 && next_i < n && next_j >= 0 && next_j < m
            && !visited[next_i][next_j] && a[next_i][next_j] == '#')
            dfs(next_i, next_j);
    }
}

// returns num of comp
int floodFill() {
    int numComp = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(!visited[i][j] && a[i][j] == '#') {
                dfs(i, j);
                numComp ++;
            }
        }
    }
    return numComp;
}

void solve() {
    if(!checkGrid())
        cout << "-1\n";
    else
        cout << floodFill() << "\n";
}

int main() {

    readInput();
    solve();

    return 0;
}