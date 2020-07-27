#include<iostream>

using namespace std;

const int N = 200005;
int n;
char a[N];
int prefixCount[N][26];

int char2int(char c) {return c - 'a';}
char int2char(int j) {return j + 'a';}

void readInput() {
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];

    for(int j = 0;j < 26;j++)
        prefixCount[0][j] = (a[0] == int2char(j) ? 1 : 0);

    for(int i = 1;i < n;i++) {
        for(int j = 0;j < 26;j++)
            prefixCount[i][j] = 
                prefixCount[i - 1][j] + (a[i] == int2char(j) ? 1 : 0);
    }
}

int getNum(int l, int r, int j) {
    return prefixCount[r][j] - (l > 0 ? prefixCount[l - 1][j] : 0);
}

int computeCost(int i, int l, int c) {
    if(l == 1)
        return (a[i] == int2char(c) ? 0 : 1);

    int halfLen = l / 2;
    int val1 = computeCost(i, halfLen, c + 1)
        + (halfLen - getNum(i + halfLen, i + l - 1, c));
    int val2 = computeCost(i + halfLen, halfLen, c + 1)
        + (halfLen - getNum(i, i + halfLen - 1, c));

    return min(val1, val2);
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        readInput();
        cout << computeCost(0, n, 0) << "\n";
    }

    return 0;
}