#include <iostream>

using namespace std;

const int N = 500;
int n, m;
char a[N][N];

void read_input() {
    scanf("%d %d ", &n, &m);

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++) 
            scanf("%c ", &a[i][j]);
}

void fill_cols(int start_col) {
    for(int j = start_col;j < m;j += 3) {
        for(int i = 0;i < n;i++)
            a[i][j] = 'X';
    }
}

int find_fill_in_col(int col) {
    for(int i = 0;i < n;i++)
        if(a[i][col] == 'X') 
            return i;

    return -1;
}

void make_bridges(int start_col) {
    for(int j = start_col;j + 1 < m;j += 3) {
        int col_idx = j + 1;
        int row_idx = find_fill_in_col(j);

        if(row_idx == -1) {
            col_idx = j;
            row_idx = find_fill_in_col(j + 1);
        }

        if(row_idx == -1)
            a[0][j] = a[0][j + 1] = 'X';
        else
            a[row_idx][col_idx] = 'X';
    }
}

void solve() {

    if(m % 3 == 1) {
        fill_cols(0);
        make_bridges(1);
    }
    else {
        fill_cols(1);
        make_bridges(2);
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            printf("%c", a[i][j]);

        printf("\n");
    }
}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        read_input();
        solve();
    }

    return 0;
}