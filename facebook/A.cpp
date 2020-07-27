#include<iostream>
#include<bitset>

using namespace std;

const int N = 55;
int n;
char I[N], O[N];
bitset<N> leftTravel[N], rightTravel[N], travel[N];

void readInput() {
    scanf("%d ", &n);

    for(int i = 0;i < n;i++)
        scanf("%c ", &I[i]);

    for(int i = 0;i < n;i++)
        scanf("%c ", &O[i]);
}

void solve() {
    for(int i = 0;i < n;i++) {
        leftTravel[i].reset();
        rightTravel[i].reset();
        travel[i].reset();
    }

    for(int i = 1;i < n;i++) {
        if(I[i - 1] == 'Y' && O[i] == 'Y') {
            leftTravel[i] = leftTravel[i - 1];
            leftTravel[i][i - 1] = true;
        }
    }

    for(int i = n - 2;i >= 0;i--) {
        if(I[i + 1] == 'Y' && O[i] == 'Y') {
            rightTravel[i] = rightTravel[i + 1];
            rightTravel[i][i + 1] = true;
        }
    }

    for(int i = 0;i < n;i++) {
        travel[i] = leftTravel[i] | rightTravel[i];
        travel[i][i] = true;

        for(int j = 0;j < n;j++) {
            if(travel[i][j])
                printf("Y");
            else
                printf("N");
        }
        printf("\n");
    }
}

int main() {

    int t;
    scanf("%d ", &t);
    for(int i = 1;i <= t;i++) {
        readInput();
        printf("Case #%d: \n", i);
        solve();
    }

    return 0;
}