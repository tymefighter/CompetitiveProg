#include<iostream>

using namespace std;

const int N = 32;
int countArr[N];

void readSolve() {
    for(int i = 0;i < N;i++)
        countArr[i] = 0;

    int n, numZeros = 0;
    cin >> n;
    for(int i = 0;i < n;i++) {
        int x, pos = -1;
        cin >> x;
        for(int j = 0;(1 << j) <= x;j++) {
            if((1 << j) & x)
                pos = j;
        }

        if(pos == -1)
            numZeros ++;
        else
            countArr[pos] ++;
    }

    long long ans = (numZeros * (numZeros - 1)) / 2;
    for(int i = 0;i < N;i++) {
        long long ct = countArr[i];
        ans += (ct * (ct - 1)) / 2;
    }

    cout << ans << "\n";
}

int main() {

    int t;
    cin >> t;
    while(t --)
        readSolve();

    return 0;
}