#include<iostream>
#include<vector>

using namespace std;


void readSolve() {
    int n;
    long long ans = 0;
    scanf("%d ", &n);

    int prevVal = -1, prevGift = 0;
    for(int i = 0;i < n;i++) {
        int curr, currGift;
        scanf("%d ", &curr);
        if(curr > prevVal)
            currGift = prevGift + 1;
        else
            currGift = 1;

        ans += currGift;
        prevVal = curr;
        prevGift = currGift;
    }

    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d ", &t);

    while(t --) {
        readSolve();
    }

    return 0;
}