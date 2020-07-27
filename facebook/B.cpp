#include<iostream>

using namespace std;

char readSolve() {
    int n, numA = 0, numB = 0;
    scanf("%d ", &n);

    for(int i = 0;i < n;i++) {
        char c;
        scanf("%c ", &c);
        if(c == 'A')
            numA ++;
        else
            numB ++;
    }

    if(abs(numA - numB) == 1)
        return 'Y';
    else
        return 'N';
}

int main() {
    int t;
    scanf("%d ", &t);

    for(int i = 1;i <= t;i++)
        printf("Case #%d: %c\n", i, readSolve());

    return 0;
}