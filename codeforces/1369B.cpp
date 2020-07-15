#include<iostream>

using namespace std;

const int N = static_cast<int>(1e5 + 5);
int n;
char s[N];

void readInput() {
    scanf("%d ", &n);
    scanf("%s ", s);
}

void solve() {
    int idx = 0;
    int numFrontZero = 0;
    while(idx < n && s[idx] == '0') {
        idx ++;
        numFrontZero ++;
    }

    idx = n - 1;
    int numBackOne = 0;
    while(idx >= 0 && s[idx] == '1') {
        idx --;
        numBackOne ++;
    }

    for(int i = 0;i < numFrontZero;i++)
        printf("0");

    if(numFrontZero + numBackOne < n)
        printf("0");

    for(int i = 0;i < numBackOne;i++)
        printf("1");

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