#include<iostream>
#include<vector>

using namespace std;

const int N = 105, M = 1005;
int n, m, x, y;
bool a[N][M];
int numW;

void readInput() {
    scanf("%d %d %d %d ", &n, &m, &x, &y);

    numW = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            char c;
            scanf("%c ", &c);
            a[i][j] = c == '.';
            numW += (a[i][j] ? 1 : 0);
        }
    }
}

int getCost() {
    if(2 * x <= y)
        return numW * x;

    int cost = 0;

    for(int i = 0;i < n;i++) {

        int start = -1;
        for(int j = 0;j < m;j++) {
            if(a[i][j]) {
                if(start == -1)
                    start = j;
            }
            else if(start != -1) {
                int len = (j - 1) - start + 1;
                cost += y * (len / 2) + (len % 2 == 0 ? 0 : x);
                start = -1;
            }
        }

        if(start != -1) {
            int len = (m - 1) - start + 1;
            cost += y * (len / 2) + (len % 2 == 0 ? 0 : x);
        }
    }

    return cost;
}

int main() {
    int t;
    scanf("%d ", &t);
    while(t --) {
        readInput();
        printf("%d\n", getCost());
    }
    return 0;
}