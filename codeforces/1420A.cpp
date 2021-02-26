#include<iostream>

using namespace std;

void readSolve() {
    int n;
    int prev, curr;
    bool possible = false;

    scanf("%d ", &n);
    scanf("%d ", &prev);

    for(int i = 1;i < n;i++) {
        scanf("%d ", &curr);
        if(prev <= curr)
            possible = true;

        prev = curr;
    }

    if(possible)
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {

    int t;
    scanf("%d ", &t);
    while(t --)
        readSolve();

    return 0;
}